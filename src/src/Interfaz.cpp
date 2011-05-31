#include "Interfaz.h"
#include"Administrar.h"

Interfaz::Interfaz(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    admin = new Administrar(this);

    connect(AdministrarPushButtonInterfaz, SIGNAL(clicked(void)), this, SLOT(showAdmin(void)));
}

/*
Interfaz::~Interfaz()
{
    delete admin;
}
*/
void Interfaz::showAdmin()
{
    admin->show();
}
