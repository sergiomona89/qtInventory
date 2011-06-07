
// Qt
#include <QInputDialog>

#include "Act_bodega.h"
#include "Administracionbodega.h"
#include "Crear_bodega.h"
#include "types.h"

AdministracionBodega::AdministracionBodega(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(NuevoPushButton, SIGNAL(clicked(void)), this, SLOT(nuevaBodega(void)));
    connect(ActualizarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizarBodega(void)));
    connect(EliminarPushButton, SIGNAL(clicked(void)), this, SLOT(eliminarBodega(void)));

    QStringList lst;
    lst << "Bodega numero" << "Nombre" << "Ubicacion" << "Teléfono" << "Descripcion" ;

    BodegasTreeWidget->setHeaderLabels(lst);

    BodegaList * bl = DBQueries::bodegas();
    setBodegas(bl);
    delete bl;
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

void AdministracionBodega::nuevaBodega()
{
    Crear_bodega cb(this);
    if(cb.exec() == QDialog::Accepted)
    {
        BodegaList * bl = DBQueries::bodegas();
        setBodegas(bl);
        delete bl;
    }
    print("paso");//aqui hay violacion de segmento.
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
