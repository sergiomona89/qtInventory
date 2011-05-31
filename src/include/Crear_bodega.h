#ifndef CREAR_BODEGA_H
#define CREAR_BODEGA_H

#include <QWidget>

namespace Ui {
class Crear_bodega;
}

class Crear_bodega : public QWidget
{
    Q_OBJECT

public:
    explicit Crear_bodega(QWidget *parent = 0);
    ~Crear_bodega();

private:
    Ui::Crear_bodega *ui;
};

#endif // CREAR_BODEGA_H
