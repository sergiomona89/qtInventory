
#include<QDebug>
#include<QApplication>

#include "DataBase.h"
#include "autenticarse.h"
#include "DBQueries.h"
#include "Info_usuario.h"

int db_options(int &argc, char **argv);
int gui(int &argc, char **argv);

void create_db(void);
void mostar_usuarios(void);


int main(int argc, char **argv)
{
    return gui(argc, argv);
}

int db_options(int& argc, char** argv)
{
    if(argc == 1)
    {
HELP:
        QString a0 = argv[0];
        qDebug() << "número de argumentos invalido, use:\n\t" + a0 + " crear\n\t" + a0 + " mostrar";
    }
    else
    {
        QString a1 = argv[1];
        if(a1 == "crear")
        {
            create_db();
            return 0;
        }
        else if(a1 == "mostrar")
        {
            mostar_usuarios();
            return 0;
        }
        else
            goto HELP;
    }

    return 0;
}

int gui(int &argc, char **argv)
{
    QApplication app(argc, argv);

    UsuarioList * ul = DBQueries::usuarios();

    for(UsuarioListIterator it = ul->begin(); it != ul->end(); it++)
    {
        Info_usuario * inf = new Info_usuario(*it);
        inf->show();
    }

    delete ul;

    return app.exec();
}

void create_db()
{
    DataBase * db = new DataBase;

    QSqlQuery query = db->dataBase()->exec();

    if(query.exec("CREATE TABLE IF NOT EXISTS tbusuario (\
		  id INTEGER PRIMARY KEY AUTOINCREMENT,\
		  nombre VARCHAR(50) NOT NULL,\
		  cargo VARCHAR(50) NOT NULL,\
		  contrasena VARCHAR(50) NOT NULL,\
		  email VARCHAR(50) NOT NULL,\
		  telefono INTEGER NOT NULL)"))
    {
        qDebug() << "creamos la tabla usuario";
    }
    else
    {
        qDebug() << "error al crear la tabla usuario";
        delete db;
        exit(-1);
    }

    query.exec("INSERT INTO tbusuario (nombre, cargo, contrasena, email, telefono) VALUES ('yo', 'admin', 'pass', 'yo@tu.com', 1234)");

    delete db;
}

void mostar_usuarios()
{
    UsuarioList * ul = DBQueries::usuarios();

    for(UsuarioListIterator it = ul->begin(); it != ul->end(); it++)
    {
        qDebug() << "Nombre: " << (*it).getNombre();
    }

    delete ul;
}