#ifndef DBQUERIES_H
#define DBQUERIES_H

#include<QtCore>

class DBQueries: public QObject
{
    Q_OBJECT
public:
    DBQueries(QObject * parent = 0);
    ~DBQueries(void);
};

#endif // DBQUERIES_H
