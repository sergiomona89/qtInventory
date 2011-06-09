
#include "Usuario.h"
#include "Bodega.h"
#include "DataStream.h"

QDataStream& DataStream::operator<<(int i)
{
    return QDataStream::operator<<(i);
}

QDataStream& DataStream::operator>>(int &i)
{
    return QDataStream::operator>>(i);
}

QDataStream& DataStream::operator>>(Usuario &usr)
{
    QString qstr;
    char * str;

    QDataStream::operator>>(usr.Id);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    usr.Nombre = QString(str);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    usr.Cargo = QString(str);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    usr.Email = QString(str);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    usr.Contrasena = QString(str);

    QDataStream::operator>>(usr.Telefono);

    return *this;
}

QDataStream& DataStream::operator<<(Usuario &usr)
{
    char * str;

    QDataStream::operator<<(usr.Id);

    str = (char *)usr.Nombre.toStdString().c_str();
    QDataStream::operator<<(str);

    str = (char *)usr.Cargo.toStdString().c_str();
    QDataStream::operator<<(str);

    str = (char *)usr.Email.toStdString().c_str();
    QDataStream::operator<<(str);

    str = (char *)usr.Contrasena.toStdString().c_str();
    QDataStream::operator<<(str);

    QDataStream::operator<<(usr.Telefono);

    return *this;
}

QDataStream& DataStream::operator>>(Bodega &bdg)
{
    QString qstr;
    char * str;

    QDataStream::operator>>(bdg.Id);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    bdg.Nombre = QString(str);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    bdg.Descripcion = QString(str);

    str = (char *)qstr.toStdString().c_str();
    QDataStream::operator>>(str);
    bdg.Direccion = QString(str);

    QDataStream::operator>>(bdg.Telefono);

    return *this;
}

QDataStream& DataStream::operator<<(Bodega &bdg)
{
    char * str;

    QDataStream::operator<<(bdg.Id);

    str = (char *)bdg.Nombre.toStdString().c_str();
    QDataStream::operator<<(str);

    str = (char *)bdg.Descripcion.toStdString().c_str();
    QDataStream::operator<<(str);

    str = (char *)bdg.Direccion.toStdString().c_str();
    QDataStream::operator<<(str);

    QDataStream::operator<<(bdg.Telefono);

    return *this;
}