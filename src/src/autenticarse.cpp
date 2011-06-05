

#include "autenticarse.h"
#include "Interfaz.h"
#include "types.h"

#include<QDebug>
#include<QMessageBox>

#define HOST	"localhost"
#define PUERTO	3490
#define TAM_BUF	260

Autenticarse::Autenticarse(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(AceptarPushButton, SIGNAL(clicked(void)), this, SLOT(autenticar(void)));
    connect(CancelarPushButton, SIGNAL(clicked(void)), this, SLOT(close(void)));

    _cliente = new Cliente(this);
    _cliente->start("127.0.0.1", PUERTO);
}

Autenticarse::~Autenticarse(void)
{
    delete _cliente;
}

void Autenticarse::autenticar()
{
    Peticion p = Autenticar;
    int id = 123;
    // envío el tipo de peticion
    _cliente->enviar(p);
    _cliente->enviar(id);
    _cliente->enviar(id);
    // leo la respuesta

//     dat = SERIALIZAR(id);
//     _cliente->enviar(dat, strlen(dat)+1);
}
