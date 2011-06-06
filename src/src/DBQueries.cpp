

#include "DBQueries.h"
#include "DataBase.h"
#include "types.h"

int DBQueries::autenticar(int id, QString contrasena)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();
    if(query.exec("SELECT tbplugin.id FROM tbplugin WHERE tbplugin.id="+QString::number(id)+" AND tbplugin.contrasena='"+contrasena+"'"))
        return 0;

    if(query.next())
    {
        delete db;
        return 1;
    }
    else
    {
        delete db;
        return 2;
    }
}

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

Bodega * DBQueries::bodega(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    if(query.exec("SELECT tbbodega.nombre, tbbodega.ubicacion, tbbodega.telefono, tbbodega.descripcion tbbodega.id FROM tbbodega WHERE tbbodega.id="+QString::number(id)) && query.next())
    {
        Bodega * bdg = new Bodega;

        bdg->setNombre(query.value(0).toString());
        bdg->setDireccion(query.value(1).toString());
        bdg->setTelefono(query.value(2).toInt());
        bdg->setDescripcion(query.value(3).toString());
        bdg->setId(query.value(4).toInt());

        return bdg;
    }

    return 0;
}

bool DBQueries::guardarBodega(Bodega &bdg)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    bool insert = query.exec("INSERT INTO tbbodega (nombre, ubicacion, descripcion, telefono) VALUES ('"+bdg.getNombre()+"', '"+bdg.getDireccion()+"', '"+bdg.getDescripcion()+"', "+QString::number(bdg.getTelefono())+")");

    delete db;

    return insert;
}

void DBQueries::eliminarBodega(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("DELETE FROM tbbodega WHERE tbbodega.id=" + QString::number(id));

    delete db;
}

void DBQueries::actualizarBodega(int id, QString nombre, QString direccion, int telefono, QString descripcion)
{
    Bodega * bdg = bodega(id);

    bdg->setNombre(nombre);
    bdg->setDireccion(direccion);
    bdg->setDescripcion(descripcion);
    bdg->setTelefono(telefono);

    eliminarBodega(id);
    guardarBodega(*bdg);

    delete bdg;
}

BodegaList * DBQueries::bodegas(void)
{
    DataBase * db = new DataBase;

    BodegaList * bl = new BodegaList;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("SELECT * FROM tbbodega");

    while(query.next())
    {
        Bodega bdg;
        bdg.setId(query.value(0).toInt());
        bdg.setNombre(query.value(1).toString());
        bdg.setDireccion(query.value(2).toString());
        bdg.setDescripcion(query.value(3).toString());
        bdg.setTelefono(query.value(4).toInt());

        bl->append(bdg);
    }

    delete db;

    return bl;
}
/////////////////////////////////////////////////////

Producto * DBQueries::producto(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    if(query.exec("SELECT * FROM tbproducto WHERE tbproducto.id="+QString::number(id)) && query.next())
    {
        Producto * pdt = new Producto;

	pdt->setId(query.value(0).toInt());
        pdt->setNombre(query.value(1).toString());
	pdt->setDescripcion(query.value(2).toString());
        pdt->setBodega(query.value(3).toString());
	pdt->setPrecioCompra(query.value(4).toString());
	pdt->setPrecioVenta(query.value(5).toString());

        return pdt;
    }

    return 0;
}

bool DBQueries::guardarProducto(Producto &pdt)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    bool insert = query.exec("INSERT INTO tbproducto (nombre, descripcion, bodega, preciocompra, precioventa) VALUES ('"+pdt.getNombre()+"', '"+pdt.getDescripcion()+"', '"+pdt.getBodega()+"', '"+ pdt.getPrecioCompra() +"', '"+ pdt.getPrecioVenta() +"')");

    delete db;

    return insert;
}

void DBQueries::actualizarProducto(int id, QString nombre, QString descripcion, QString bodega, QString preciocompra, QString precioventa)
{
    Producto * pdt= producto(id);

    pdt->setNombre(nombre);
    pdt->setDescripcion(descripcion);
    pdt->setBodega(bodega);
    pdt->setPrecioCompra(preciocompra);
    pdt->setPrecioVenta(precioventa);

    eliminarProducto(id);
    guardarProducto(*pdt);

    delete pdt;
}

void DBQueries::eliminarProducto(int id)
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("DELETE FROM tbproducto WHERE tbproducto.id=" + QString::number(id));

    delete db;
}

ProductoList * DBQueries::productos(void)
{
    DataBase * db = new DataBase;

    ProductoList * pl = new ProductoList;

    QSqlQuery query = db->dataBase()->exec();

    query.exec("SELECT * FROM tbproducto");

    while(query.next())
    {
        Producto pdt;

	pdt.setId(query.value(0).toInt());
        pdt.setNombre(query.value(1).toString());
	pdt.setDescripcion(query.value(2).toString());
        pdt.setBodega(query.value(3).toString());
	pdt.setPrecioCompra(query.value(4).toString());
	pdt.setPrecioVenta(query.value(5).toString());

        pl->append(pdt);
    }

    delete db;

    return pl;
}

