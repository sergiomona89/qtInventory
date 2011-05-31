#ifndef CREAR_PRODUCTO_H
#define CREAR_PRODUCTO_H

#include <QWidget>

namespace Ui {
    class Crear_producto;
}

class Crear_producto : public QWidget
{
    Q_OBJECT

public:
    explicit Crear_producto(QWidget *parent = 0);
    ~Crear_producto();

private:
    Ui::Crear_producto *ui;
};

#endif // CREAR_PRODUCTO_H
