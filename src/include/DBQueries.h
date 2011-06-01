

#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>
#include"Usuario.h"
// #include "../../../../MySources/kdebase/tmp/src/KeyboardTranslator.h"

struct stat;
typedef QList<Usuario> UsuarioList;
typedef QList<Usuario>::iterator UsuarioListIterator;

class DBQueries: public QObject
{
    Q_OBJECT
public:
    DBQueries(QObject * parent = 0): QObject(parent) {}

    static void actualizarUsuario(QString nombre, QString cargo, int id, QString contrasena = QString(""));
    static Usuario * usuario(int id);
    static UsuarioList * usuarios(void);
    static bool guardarUsuario(Usuario &usr);
    static void eliminarUsuario(int id);
};

#endif // DBQUERIES_H
