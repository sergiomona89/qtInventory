
#ifndef CREAR_PRODUCTO_H
#define CREAR_PRODUCTO_H

#include <QDialog>
#include "Producto.h"
#include "ui_Crear_producto.h"
#include "DBQueries.h"

class Crear_producto : public QDialog, Ui::Crear_producto
{
    Q_OBJECT
    int indBodega[];

public:
    
    Crear_producto(QWidget *parent = 0);

public slots:
    void crear(void);
};

#endif // CREAR_PRODUCTO_H
