
#include "Administrar.h"
#include "autenticarse.h"
#include "Interfaz.h"
#include "types.h"

#include<QDebug>
#include<QMessageBox>

#define TAM_BUF		260

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
    int p = Autenticar;
    QString id = IdUsuarioLineEdit->text();
    QString pass = ContrasenaLineEdit->text();
    // envío el tipo de peticion
    if(_cliente->estado() == conectado)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);
        out << p;
        out << id;
        out << pass;
        out.device()->seek(0);
        _cliente->client()->write(block);
        _cliente->client()->flush();
        connect(_cliente->client(), SIGNAL(readyRead()), this, SLOT(startRead()));
    }
}

void Autenticarse::startRead()
{
    QDataStream in(_cliente->client());
    in.setVersion(QDataStream::Qt_4_7);
    int r;
    in >> r;

    if(r == 0)
    {
        QMessageBox::critical(this, "Error", "No se ha podido abrir la base de datos");
    }
    else if(r == 1)
    {
        Administrar * admin = new Administrar;
        admin->show();
        hide();
    }
    else if(r == 2)
    {
        QMessageBox::critical(this, "Error", "No se ha encontrado el usuario");
    }

    disconnect(this);
}