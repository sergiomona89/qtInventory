
// Qt
#include <QInputDialog>

#include "Act_usuario.h"
#include "AdministracionUsuario.h"
#include "Crear_usuario.h"

AdministracionUsuario::AdministracionUsuario(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(NuevoPushButton, SIGNAL(clicked(void)), this, SLOT(nuevoUsuario(void)));
    connect(ActualizarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizarUsuario(void)));
    connect(EliminarPushButton, SIGNAL(clicked(void)), this, SLOT(eliminarUsuario(void)));

    QStringList lst;
    lst << "Id" << "Nombre" << "Cargo" << "Email" << "Teléfono";

    UsuariosTreeWidget->setHeaderLabels(lst);

    UsuarioList * ul = DBQueries::usuarios();
    setUsuarios(ul);
    delete ul;
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

void AdministracionUsuario::nuevoUsuario()
{
    Crear_usuario cu(this);
    if(cu.exec() == QDialog::Accepted)
    {
        UsuarioList * ul = DBQueries::usuarios();
        setUsuarios(ul);
        delete ul;
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
