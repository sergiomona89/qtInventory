
#ifndef BODEGA_H
#define BODEGA_H

#include<QtCore>

class Bodega
{
public:
    Bodega();

    QString getDireccion(void);
    QString getNombre(void);
    int getTelefono(void);

    void setDireccion(QString direccion);
    void setNombre(QString nombre);
    void setTelefono(int telefono);

    protected:
    QString Direccion;
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

inline int Bodega::getTelefono()
{
    return Telefono;
}

inline void Bodega::setDireccion(QString direccion)
{
    Direccion = direccion;
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
