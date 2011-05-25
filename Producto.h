#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<QtCore>

class Producto
{
public:
    Producto(void);
    ~Producto(void);

    QString getBodega(void);
    QString getDescripcion(void);
    QString getNombre(void);
    float getPrecioCompra(void);
    float getPrecioVenta(void);



    void setBodega(QString bodega);
    void setDescripcion(QString description);
    void setNombre(QString nombre);
    void setPrecioCompra(float precio);
    void setPrecioVenta(float precio);


protected:
    QString Bodega;
    QString Descripcion;
    QString Nombre;
    QString PrecioCompra;

    QString PrecioVenta;

};

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

inline float Producto::getPrecioCompra()
{
    return PrecioCompra;
}

inline float Producto::getPrecioVenta()
{
    return PrecioVenta;
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

inline void Producto::setPrecioCompra(float precio)
{
    PrecioCompra = precio;
}

inline void Producto::setPrecioVenta(float precio)
{
    PrecioVenta = precio;
}

#endif // PRODUCTO_H
