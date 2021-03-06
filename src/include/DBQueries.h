

#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>
#include "Usuario.h"
#include "Bodega.h"
#include "Producto.h"

typedef QList<Usuario> UsuarioList;
typedef QList<Usuario>::iterator UsuarioListIterator;
typedef QList<Bodega> BodegaList;
typedef QList<Bodega>::iterator BodegaListIterator;
typedef QList<Producto> ProductoList;
typedef QList<Producto>::iterator ProductoListIterator;

class DBQueries
{
public:
    DBQueries(void) {}

    // 0 error
    // 1 autentica
    // 2 no autentica
    static int autenticar(int id, QString contrasena);
    static void actualizarUsuario(QString nombre, QString cargo, int id, QString contrasena = QString(""));
    static Usuario * usuario(int id);
    static UsuarioList * usuarios(void);
    static bool guardarUsuario(Usuario &usr);
    static void eliminarUsuario(int id);
    static Bodega * bodega(int id);
    static bool guardarBodega(Bodega &bdg);
    static void actualizarBodega(int id, QString nombre, QString direccion, int telefono, QString descripcion);
    static void eliminarBodega(int id);
    static BodegaList * bodegas(void);
    
    static Producto * producto(int id);
    static bool guardarProducto(Producto &pdt);
    static void actualizarProducto(int id, QString nombre, QString descripcion, QString bodega, QString precioCompra, QString precioVenta);
    static void eliminarProducto(int id);
    static ProductoList * productos(void);
};

#endif // DBQUERIES_H
