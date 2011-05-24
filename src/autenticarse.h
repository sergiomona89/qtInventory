#ifndef AUTENTICARSE_H
#define AUTENTICARSE_H

#include <QWidget>
#include "ui_autenticarse.h"

class Autenticarse : public QDialog, Ui::Autenticacion
{
    Q_OBJECT
public:
    Autenticarse(QWidget *parent = 0);

signals:

public slots:

};

#endif // AUTENTICARSE_H
