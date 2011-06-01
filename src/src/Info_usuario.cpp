
#include "Usuario.h"
#include "Info_usuario.h"


Info_usuario::Info_usuario(Usuario &usr, QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    setUsuario(usr);

    connect(AceptarPushButton, SIGNAL(clicked(void)), this, SLOT(close()));
}

void Info_usuario::setUsuario(Usuario &usr)
{
    IdLabel->setText(QString::number(usr.getId()));
    NombreLabel->setText(usr.getNombre());
    CargoLabel->setText(usr.getCargo());
    EmailLabel->setText(usr.getEmail());
    TelefonoLabel->setText(QString::number(usr.getTelefono()));
}
