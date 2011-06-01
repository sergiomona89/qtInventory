

#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>
#include"Usuario.h"
// #include "../../../../MySources/kdebase/tmp/src/KeyboardTranslator.h"

typedef QList<Usuario> UsuarioList;
typedef QList<Usuario>::iterator UsuarioListIterator;

class DBQueries: public QObject
{
    Q_OBJECT
public:
    DBQueries(QObject * parent = 0);
    ~DBQueries(void);

    static UsuarioList * usuarios(void);
    static bool guardarUsuario(Usuario &usr);
};

#endif // DBQUERIES_H
