
#include"Servidor.h"
#include<QUdpSocket>

Servidor::Servidor(QObject* parent)
{
    _socket = new QUdpSocket(this);
    _socket->bind(PUERTO);

    connect(_socket, SIGNAL(readyRead(void)), this, SLOT(readPendingDatagrams(void)));
}

Servidor::~Servidor()
{
    delete _socket;
}

void Servidor::readPendingDatagrams()
{
     while (_socket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(_socket->pendingDatagramSize());
         _socket->readDatagram(datagram.data(), datagram.size());
//          statusLabel->setText(tr("Received datagram: \"%1\"")
//                               .arg(datagram.data()));
     }
}