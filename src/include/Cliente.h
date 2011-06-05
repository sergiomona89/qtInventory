
#ifndef CLIENTE_H
#define CLIENTE_H

#include<QtNetwork>
#include"types.h"

#define TEMPLATE	template<typename type>

enum EstadoDelServidor { conectado, desconectado, enEspera };

class Cliente: public QObject
{
    Q_OBJECT
public:
    Cliente(QObject* parent = 0);
    ~Cliente();
    void start(QString address, quint16 port);

    EstadoDelServidor estado(void) const;
    QTcpSocket * client(void) const;

    TEMPLATE qint64 enviar(type &d);

public slots:
    void startTransfer();
protected:
    QTcpSocket * _client;
    EstadoDelServidor _estado;

//     TEMPLATE qint64 recivir(type &d);
};

inline EstadoDelServidor Cliente::estado(void) const
{
    return _estado;
}

inline QTcpSocket * Cliente::client(void) const
{
    return _client;
}

TEMPLATE qint64 Cliente::enviar(type &d)
{
    if(_estado == conectado)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);
        out << d;
        out.device()->seek(0);
        _client->write(block);
        _client->flush();
        /*
        qDebug() << "enviamos r: " << d;
               char * dat = SERIALIZAR(d);
        if(!_client->isOpen())
          _client->open(QIODevice::ReadWrite);
               qint64 r = _client->write(dat, strlen(dat)+1);
        _client->close();
              */
    }
    return -1;
}

// TEMPLATE qint64 Cliente::recivir(type &d)
// {
//     if(_estado == conectado)
//     {
//         return _client->read(DESERIALIZAR(d), _client->bytesAvailable());
//     }
//     return -1;
// }

#endif