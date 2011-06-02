

#ifndef AUTENTICARSE_H
#define AUTENTICARSE_H

#include <QWidget>
#include "ui_autenticarse.h"

class Autenticarse : public QWidget, Ui::Autenticarse
{
    Q_OBJECT
public:
    Autenticarse(QWidget *parent = 0);

protected slots:
    void autenticar(void);
};

#endif // AUTENTICARSE_H
