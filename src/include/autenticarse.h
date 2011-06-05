

#ifndef AUTENTICARSE_H
#define AUTENTICARSE_H

#include <QWidget>
#include "Cliente.h"
#include "ui_autenticarse.h"

class Autenticarse : public QWidget, Ui::Autenticarse
{
    Q_OBJECT
public:
    Autenticarse(QWidget *parent = 0);
    ~Autenticarse(void);

protected:
    Cliente * _cliente;

protected slots:
    void autenticar(void);
    void startRead(void);
};

#endif // AUTENTICARSE_H
