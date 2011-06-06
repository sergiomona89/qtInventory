
// Qt
#include <QMessageBox>
#include <QInputDialog>

#include "Act_usuario.h"
#include "AdministracionUsuario.h"
#include "Crear_usuario.h"
#include "Cliente.h"
#include "DataStream.h"

AdministracionUsuario::AdministracionUsuario(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(NuevoPushButton, SIGNAL(clicked(void)), this, SLOT(nuevoUsuario(void)));
    connect(ActualizarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizarUsuario(void)));
    connect(EliminarPushButton, SIGNAL(clicked(void)), this, SLOT(eliminarUsuario(void)));

    QStringList lst;
    lst << "Id" << "Nombre" << "Cargo" << "Email" << "Teléfono";

    UsuariosTreeWidget->setHeaderLabels(lst);

    _cliente = new Cliente(this);
    _cliente->start("127.0.0.1", PUERTO);
    connect(_cliente->client(), SIGNAL(connected(void)), this, SLOT(descargarUsuarios()));
}

void AdministracionUsuario::setUsuarios(UsuarioList * lst)
{
    UsuariosTreeWidget->clear();
    for(UsuarioListIterator it = lst->begin(); it != lst->end(); it++)
    {
        Usuario * usr = &(*it);
        QTreeWidgetItem * item = new QTreeWidgetItem(UsuariosTreeWidget);
        item->setText(0, QString::number(usr->getId()));
        item->setText(1, usr->getNombre());
        item->setText(2, usr->getCargo());
        item->setText(3, usr->getEmail());
        item->setText(4, QString::number(usr->getTelefono()));
    }
}

void AdministracionUsuario::descargarUsuarios()
{
    int p = DatosUsuarios;
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

void AdministracionUsuario::nuevoUsuario()
{
    Crear_usuario cu(this);
    if(cu.exec() == QDialog::Accepted)
    {
        delete _cliente;
        _cliente = new Cliente(this);
        _cliente->start("127.0.0.1", PUERTO);
        connect(_cliente->client(), SIGNAL(connected(void)), this, SLOT(descargarUsuarios()));
//       descargarUsuarios();
//         UsuarioList * ul = DBQueries::usuarios();
//         setUsuarios(ul);
//         delete ul;
    }
}

void AdministracionUsuario::actualizarUsuario()
{
    QInputDialog id(this);
    id.setLabelText("Ingrese el id del usuario a actualizar");
    if(id.exec() == QDialog::Accepted)
    {
        Usuario * usr = DBQueries::usuario(id.textValue().toInt());
        if(usr == 0)
            return;
        Act_usuario au(usr->getNombre(), usr->getCargo(), usr->getId(), this);
        if(au.exec() == QDialog::Accepted)
        {
            UsuarioList * ul = DBQueries::usuarios();
            setUsuarios(ul);
            delete ul;
        }
        delete usr;
    }
}

void AdministracionUsuario::eliminarUsuario()
{
    QInputDialog id(this);
    id.setLabelText("Ingrese el id del usuario a eliminar");
    if(id.exec() == QDialog::Accepted)
    {
        DBQueries::eliminarUsuario(id.textValue().toInt());

        UsuarioList * ul = DBQueries::usuarios();
        setUsuarios(ul);
        delete ul;
    }
}

void AdministracionUsuario::startRead()
{
    DataStream in(_cliente->client());
    in.setVersion(QDataStream::Qt_4_7);
    int len = 0;
    in >> len;

    if(len == 0)
    {
        QMessageBox::critical(this, "Administracion Usuario", "No se ha podido abrir la base de datos");
    }
    else
    {
        UsuarioList * ul = new UsuarioList;
        for(int i = 0; i < len; i++)
        {
            Usuario usr;
            in >> usr;
            ul->append(usr);
        }
        setUsuarios(ul);
    }

    disconnect(this);
}