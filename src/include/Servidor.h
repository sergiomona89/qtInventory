
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QtNetwork>
#include "types.h"

#define TEMPLATE	template<typename type>

class Servidor: public QObject
{
    Q_OBJECT
public:
    Servidor(QObject * parent = 0);
    ~Servidor();

public slots:
    void acceptConnection();
    void startRead();
signals:
    void readed(bool); // verdadero cuando la lectura es correcta
protected:
    QTcpServer * _server;
    QTcpSocket * _client;

    TEMPLATE qint64 enviar(type &d);
    TEMPLATE qint64 recivir(type &d);
};

TEMPLATE qint64 Servidor::enviar(type &d)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << d;
    out.device()->seek(0);
    _client->write(block);
    _client->flush();
}

#endif