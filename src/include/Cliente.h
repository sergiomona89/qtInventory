
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

    TEMPLATE qint64 enviar(type &d);

public slots:
    void startTransfer();
protected:
    QTcpSocket * _client;
    EstadoDelServidor _estado;

    TEMPLATE qint64 recivir(type &d);
};

TEMPLATE qint64 Cliente::enviar(type &d)
{
    if(_estado == conectado)
    {
        char * dat = SERIALIZAR(d);
        qint64 r = _client->write(dat, strlen(dat)+1);
        _client->flush();
    }
    return -1;
}

TEMPLATE qint64 Cliente::recivir(type &d)
{
    if(_estado == conectado)
    {
        return _client->read(DESERIALIZAR(d), _client->bytesAvailable());
    }
    return -1;
}

#endif