#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include"ui_interfaz.h"
class Administrar;

class Interfaz : public QDialog, Ui::Interfaz
{
    Q_OBJECT
public:
    Interfaz(QWidget *parent = 0);
    //~Interfaz(void);

signals:

public slots:
    void showAdmin(void);

protected:
    Administrar * admin;
};

#endif // INTERFAZ_H
