
#ifndef CREAR_BODEGA_H
#define CREAR_BODEGA_H

#include <QDialog>
#include "Bodega.h"
#include "ui_Crear_bodega.h"
#include "DBQueries.h"

class Crear_bodega : public QDialog, Ui::Crear_bodega
{
    Q_OBJECT

public:
    Crear_bodega(QWidget *parent = 0);

public slots:
    void crear(void);
};

#endif // CREAR_BODEGA_H
