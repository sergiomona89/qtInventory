
#include "DBQueries.h"
#include "DataBase.h"

DBQueries::DBQueries(QObject * parent):
    QObject(parent)
{
}

DBQueries::~DBQueries()
{
}

UsuarioList * DBQueries::usuarios(void)
{
    DataBase * db = new DataBase;

    UsuarioList * ul = new UsuarioList;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("SELECT tbusuario.id, tbusuario.nombre, tbusuario.cargo, tbusuario.contrasena, tbusuario.email, tbusuario.telefono FROM tbusuario");

    while(query.next())
    {
        Usuario u;

        u.setId(query.value(0).toInt());
        u.setNombre(query.value(1).toString());
        u.setCargo(query.value(2).toString());
        u.setContrasena(query.value(3).toString());
        u.setEmail(query.value(4).toString());
        u.setTelefono(query.value(5).toInt());

        ul->append(u);
    }

    delete db;

    return ul;
}