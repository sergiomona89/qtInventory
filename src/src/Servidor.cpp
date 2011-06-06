
#include"DBQueries.h"
#include"types.h"
#include"Servidor.h"
#include"DataStream.h"

Servidor::Servidor(QObject* parent): QObject(parent)
{
    _server = new QTcpServer(this);

    connect(_server, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));

    _server->listen(QHostAddress::Any, PUERTO);
}

Servidor::~Servidor()
{
    _server->close();
}

void Servidor::acceptConnection()
{
    _client = _server->nextPendingConnection();

    connect(_client, SIGNAL(readyRead()), this, SLOT(startRead()));
}

void Servidor::startRead()
{
    QDataStream in(_client);
    in.setVersion(QDataStream::Qt_4_7);
    int p;
    in >> p;
    
    print(p);

    if(p == Autenticar)
    {
        QString id;
        QString pass;
        in >> id;
        in >> pass;
        int r = DBQueries::autenticar(id.toInt(), pass);

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);
        out << r;
	out.device()->seek(0);
        _client->write(block);
        _client->flush();
    }
    else if(p == DatosUsuarios)
    {
        QByteArray block;
        DataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);

        UsuarioList * ul = DBQueries::usuarios();

        out << ul->length();

        for(UsuarioListIterator it = ul->begin(); it != ul->end(); it++)
        {
            out << (*it);
        }
        delete ul;
        _client->write(block);
        _client->flush();
    }
    else
    {
        Respuesta r = error;
        enviar(r);
    }
}