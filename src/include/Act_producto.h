
#ifndef ACT_PRODUCTO_H
#define ACT_PRODUCTO_H

#include <QDialog>
#include "ui_Act_producto.h"

class Act_producto : public QDialog, Ui::Act_producto
{
  Q_OBJECT
  
private:
  int indBodega[];

public:
  Act_producto(int id, QString nombre, QString descripcion, QString bodega, QString precioCompra, QString precioVenta, QWidget *parent = 0);
  
protected slots:
    void actualizar(void);
    
};

#endif // ACT_PRODUCTO_H
