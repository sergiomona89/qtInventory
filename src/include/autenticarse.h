#ifndef AUTENTICARSE_H
#define AUTENTICARSE_H

#include <QWidget>
#include "ui_autenticarse.h"

class Autenticarse : public QDialog, Ui::Autenticarse
{
    Q_OBJECT
public:
    Autenticarse(QWidget *parent = 0);

signals:

protected slots:
    void autenticar(void);
};

#endif // AUTENTICARSE_H
