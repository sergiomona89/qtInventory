
#ifndef DATABASE_H
#define DATABASE_H

#include<QtSql>

#define DB_TYPE	"QSQLITE"
#define DB_NAME "test.sql"

class DataBase: public QObject {
    Q_OBJECT
public:
    DataBase(QObject * parent = 0);
    ~DataBase(void);

    bool isOpen(void);

    void close(void);
    void destroy(void);

    QSqlDatabase * dataBase(void) const;

signals:
    void error(QString message);

protected:
    QSqlDatabase * db;
    QString dbName;
};

inline QSqlDatabase * DataBase::dataBase(void) const
{
    return db;
}

#endif
