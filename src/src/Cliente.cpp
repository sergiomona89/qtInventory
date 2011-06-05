
#include "Cliente.h"
#include "types.h"

#include <QHostAddress>

Cliente::Cliente(QObject* parent): QObject(parent)
{
    _client = new QTcpSocket(this);
    connect(_client, SIGNAL(connected()), this, SLOT(startTransfer()));
    _estado = desconectado;
}

Cliente::~Cliente()
{
    _client->close();
}

void Cliente::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    _client->connectToHost(addr, port);
}

void Cliente::startTransfer()
{
    _estado = conectado;
//     Peticion p = Autenticar;
//     char * data = SERIALIZAR(p);
//     _client->write(data, strlen(data)+1);
}