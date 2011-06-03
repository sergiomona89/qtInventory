

#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>
#include "Usuario.h"
#include "Bodega.h"

typedef QList<Usuario> UsuarioList;
typedef QList<Usuario>::iterator UsuarioListIterator;

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
    static Bodega * bodega(int telefono);
    static bool guardarBodega(Bodega &bdg);
    static void actualizarBodega(QString nombre = QString(""), QString direccion = QString(""), int telefono = 0, QString descripcion = QString(""));
    static void eliminarBodega(int telefono);
};

#endif // DBQUERIES_H
