
#ifndef BODEGA_H
#define BODEGA_H

#include<QString>

class Bodega
{
public:
    Bodega(void):  Direccion(""), Nombre(""), Descripcion(""), Telefono(0), Id(0) {}
    ~Bodega(void) {}

    QString getDireccion(void);
    QString getNombre(void);
    QString getDescripcion(void);
    int getTelefono(void);
    int getId(void);

    void setDireccion(QString direccion);
    void setNombre(QString nombre);
    void setDescripcion(QString descripcion);
    void setTelefono(int telefono);
    void setId(int id);

protected:
    QString Direccion;
    QString Nombre;
    QString Descripcion;
    int Telefono;
    int Id;

    friend class DataStream;
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

inline int Bodega::getId()
{
    return Id;
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

inline void Bodega::setId(int id)
{
    Id = id;
}

#endif // BODEGA_H
