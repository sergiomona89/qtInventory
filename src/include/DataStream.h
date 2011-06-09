
#ifndef DATASTREAM_H
#define DATASTREAM_H

#include<QDataStream>

class Usuario;
class Bodega;

class DataStream: public QDataStream
{
public:
    DataStream(QIODevice * d): QDataStream(d) {}
    DataStream(QByteArray * a, QIODevice::OpenMode mode): QDataStream(a, mode) {}

    QDataStream& operator<<(int i);
    QDataStream& operator>>(int &i);

    QDataStream& operator>>(Usuario &usr);
    QDataStream& operator<<(Usuario &usr);

    QDataStream& operator>>(Bodega &bdg);
    QDataStream& operator<<(Bodega &bdg);
};

#endif
