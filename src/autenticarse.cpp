#include "autenticarse.h"
#include"Interfaz.h"

Autenticarse::Autenticarse(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect(this, SIGNAL(accepted(void)), this, SLOT(autenticar(void)));
}

void Autenticarse::autenticar()
{
    // valido la info en el server
    Interfaz * i = new Interfaz;
    i->show();
}
