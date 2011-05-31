

#include"DataBase.h"


DataBase::DataBase(QObject * parent):
    QObject(parent)
{
    db = new QSqlDatabase;

    QString db_path = DB_NAME;

    db = new QSqlDatabase(QSqlDatabase::addDatabase(DB_TYPE, DB_NAME));
    db->setDatabaseName(db_path);
    dbName = DB_NAME;
    if (!db->open()) {
        emit error("Could not open database");
        qDebug() << "Could not open database";
    }
}

DataBase::~DataBase()
{
    if(db)
    {
        close();
        destroy();
    }
}

bool DataBase::isOpen(void)
{
    return db->isOpen();
}

void DataBase::close()
{
    if(db)
    {
        db->close();
        delete db;
        db = 0;
    }
}

void DataBase::destroy()
{
    QSqlDatabase::removeDatabase(dbName);
}

