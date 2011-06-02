

#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>
#include "Usuario.h"

typedef QList<Usuario> UsuarioList;
typedef QList<Usuario>::iterator UsuarioListIterator;

class DBQueries
{
public:
    DBQueries(void) {}

    static bool autenticar(int id, QString contrasena);
    static void actualizarUsuario(QString nombre, QString cargo, int id, QString contrasena = QString(""));
    static Usuario * usuario(int id);
    static UsuarioList * usuarios(void);
    static bool guardarUsuario(Usuario &usr);
    static void eliminarUsuario(int id);
};

#endif // DBQUERIES_H
