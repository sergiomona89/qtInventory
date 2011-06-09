#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<QtCore>

class Producto
{
public:
    Producto(void): Bodega(""), Descripcion(""), Nombre(""), PrecioCompra(""), PrecioVenta(""), Id(0) {}
    ~Producto(void) {}

    int getId(void);
    QString getBodega(void);
    QString getDescripcion(void);
    QString getNombre(void);
    QString getPrecioCompra(void);
    QString getPrecioVenta(void);



    void setId(int id);
    void setBodega(QString bodega);
    void setDescripcion(QString description);
    void setNombre(QString nombre);
    void setPrecioCompra(QString precio);
    void setPrecioVenta(QString precio);


protected:
    QString Bodega;
    QString Descripcion;
    QString Nombre;
    QString PrecioCompra;
    QString PrecioVenta;
    int Id;

};

inline int Producto::getId()
{
    return Id;
}

inline QString Producto::getBodega()
{
    return Bodega;
}

inline QString Producto::getDescripcion()
{
    return Descripcion;
}

inline QString Producto::getNombre()
{
    return Nombre;
}

inline QString Producto::getPrecioCompra()
{
    return PrecioCompra;
}

inline QString Producto::getPrecioVenta()
{
    return PrecioVenta;
}

inline void Producto::setId(int id)
{
    Id = id;
}

inline void Producto::setBodega(QString bodega)
{
    Bodega = bodega;
}

inline void Producto::setDescripcion(QString descripcion)
{
    Descripcion = descripcion;
}

inline void Producto::setNombre(QString nombre)
{
    Nombre = nombre;
}

inline void Producto::setPrecioCompra(QString precio)
{
    PrecioCompra = precio;
}

inline void Producto::setPrecioVenta(QString precio)
{
    PrecioVenta = precio;
}

#endif // PRODUCTO_H
