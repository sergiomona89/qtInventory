
#ifndef ADMINISTRACIONPRODUCTO_H
#define ADMINISTRACIONPRODUCTO_H

#include <QDialog>
#include "ui_AdministracionProducto.h"
#include "DBQueries.h"

class AdministracionProducto : public QDialog, Ui::AdeminstracionProducto
{
      Q_OBJECT

public:
    AdministracionProducto(QWidget *parent = 0);
    ~AdministracionProducto(void) {}

    void setProductos(ProductoList * lst);

public slots:
    void nuevoProducto(void);
    void actualizarProducto(void);
    void eliminarProducto(void);
};

#endif // ADMINISTRACIONPRODUCTO_H
