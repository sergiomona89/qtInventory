
#ifndef BODEGA_H
#define BODEGA_H

#include<QtCore>

class Bodega
{
public:
    Bodega();

    QString getDireccion(void);
    QString getNombre(void);
    QString getDescripcion(void);
    int getTelefono(void);

    void setDireccion(QString direccion);
    void setDescripcion(QString descripcion);
    void setNombre(QString nombre);
    void setTelefono(int telefono);

protected:
    QString Direccion;
    QString Descripcion;
    QString Nombre;
    int telefono;
};

inline QString Bodega::getDireccion()
{
    return Direccion;
}

inline QString Bodega::getNombre()
{
    return Nombre;
}

inline QString Bodega::getDescripcion()
{
    return Descripcion;
}

inline int Bodega::getTelefono()
{
    return Telefono;
}

inline void Bodega::setDireccion(QString direccion)
{
    Direccion = direccion;
}

inline void Bodega::setDescripcion(QString descripcion)
{
    Descripcion = descripcion;
}

inline void Bodega::setNombre(QString nombre)
{
    Nombre = nombre;
}

inline void Bodega::setTelefono(int telefono)
{
    Telefono = telefono;
}

#endif // BODEGA_H
