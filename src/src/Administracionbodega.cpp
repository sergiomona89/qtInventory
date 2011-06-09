
// Qt
#include <QMessageBox>
#include <QInputDialog>

#include "Act_bodega.h"
#include "Administracionbodega.h"
#include "Crear_bodega.h"
#include "Cliente.h"
#include "DataStream.h"
#include "types.h"

AdministracionBodega::AdministracionBodega(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(NuevoPushButton, SIGNAL(clicked(void)), this, SLOT(nuevaBodega(void)));
    connect(ActualizarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizarBodega(void)));
    connect(EliminarPushButton, SIGNAL(clicked(void)), this, SLOT(eliminarBodega(void)));

    QStringList lst;
    lst << "Bodega numero" << "Nombre" << "Ubicacion" << "Teléfono" << "Descripcion" ;

    BodegasTreeWidget->setHeaderLabels(lst);

    _cliente = new Cliente(this);
    _cliente->start("127.0.0.1", PUERTO);
    connect(_cliente->client(), SIGNAL(connected(void)), this, SLOT(descargarBodegas()));

//     BodegaList * bl = DBQueries::bodegas();
//     setBodegas(bl);
//     delete bl;
}

void AdministracionBodega::setBodegas(BodegaList * lst)
{
    BodegasTreeWidget->clear();
    for(BodegaListIterator it = lst->begin(); it != lst->end(); it++)
     {
        Bodega * bdg = &(*it);
        QTreeWidgetItem * item = new QTreeWidgetItem(BodegasTreeWidget);
        item->setText(0, QString::number(bdg->getId()));
        item->setText(1, bdg->getNombre());
        item->setText(2, bdg->getDireccion());
        item->setText(3, QString::number(bdg->getTelefono()));
        item->setText(4, bdg->getDescripcion());
    }
}

void AdministracionBodega::descargarBodegas()
{
    int p = DatosBodegas;
    if(_cliente->estado() == conectado)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);
        out << p;
        out.device()->seek(0);
        _cliente->client()->write(block);
        _cliente->client()->flush();
        connect(_cliente->client(), SIGNAL(readyRead()), this, SLOT(startRead()));
    }
}

void AdministracionBodega::nuevaBodega()
{
    Crear_bodega cb(this);
    if(cb.exec() == QDialog::Accepted)
    {
        BodegaList * bl = DBQueries::bodegas();
        setBodegas(bl);
        delete bl;
    }
}

void AdministracionBodega::actualizarBodega()
{
    QInputDialog id(this);
    id.setLabelText("Ingrese el numero de la bodega a actualizar");
    if(id.exec() == QDialog::Accepted)
    {
        Bodega * bdg = DBQueries::bodega(id.textValue().toInt());
        if(bdg == 0)
            return;
        Act_bodega ab(bdg->getNombre(), bdg->getDireccion(), bdg->getDescripcion(), bdg->getTelefono(), bdg->getId(), this);
        if(ab.exec() == QDialog::Accepted)
        {
            BodegaList * bl = DBQueries::bodegas();
            setBodegas(bl);
            delete bl;
        }
        delete bdg;
    }
}

void AdministracionBodega::eliminarBodega()
{
    QInputDialog id(this);
    id.setLabelText("Ingrese el numero de la bodega a eliminar");
    if(id.exec() == QDialog::Accepted)
    {
        DBQueries::eliminarBodega(id.textValue().toInt());

        BodegaList * bl = DBQueries::bodegas();
        setBodegas(bl);
        delete bl;
    }
}

void AdministracionBodega::startRead()
{
    DataStream in(_cliente->client());
    in.setVersion(QDataStream::Qt_4_7);
    int len = 0;
    in >> len;

    if(len == 0)
    {
        QMessageBox::critical(this, "Administracion Bodega", "No se ha podido abrir la base de datos");
    }
    else
    {
        BodegaList * bl = new BodegaList;
        for(int i = 0; i < len; i++)
        {
            Bodega bdg;
            in >> bdg;
            bl->append(bdg);
        }
        setBodegas(bl);
    }

    disconnect(this);
}
