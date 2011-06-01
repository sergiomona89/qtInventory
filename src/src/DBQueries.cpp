

#include "DBQueries.h"
#include "DataBase.h"


void DBQueries::actualizarUsuario(QString nombre, QString cargo, int id, QString contrasena)
{
    Usuario * usr = usuario(id);

    usr->setNombre(nombre);
    usr->setCargo(cargo);
    usr->setId(id);
    if(contrasena != "")
    {
        usr->setContrasena(contrasena);
    }

    eliminarUsuario(id);
    guardarUsuario(*usr);

    delete usr;
}

Usuario * DBQueries::usuario(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    if(query.exec("SELECT tbusuario.id, tbusuario.nombre, tbusuario.cargo, tbusuario.contrasena, tbusuario.email, tbusuario.telefono FROM tbusuario WHERE tbusuario.id="+QString::number(id)) && query.next())
    {
        Usuario * u = new Usuario;

        u->setId(query.value(0).toInt());
        u->setNombre(query.value(1).toString());
        u->setCargo(query.value(2).toString());
        u->setContrasena(query.value(3).toString());
        u->setEmail(query.value(4).toString());
        u->setTelefono(query.value(5).toInt());

        return u;
    }

    return 0;
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

bool DBQueries::guardarUsuario(Usuario &usr)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    bool insert = query.exec("INSERT INTO tbusuario (id, nombre, cargo, contrasena, email, telefono) VALUES ("+QString::number(usr.getId())+", '" +usr.getNombre()+"', '"+usr.getCargo()+"', '"+usr.getContrasena()+"', '"+usr.getEmail()+"', "+QString::number(usr.getTelefono())+")");

    delete db;

    return insert;
}

void DBQueries::eliminarUsuario(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("DELETE FROM tbusuario WHERE tbusuario.id=" + QString::number(id));

    delete db;
}
