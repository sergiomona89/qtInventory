#include "Crear_producto.h"
#include "ui_Crear_producto.h"

Crear_producto::Crear_producto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crear_producto)
{
    ui->setupUi(this);
}

Crear_producto::~Crear_producto()
{
    delete ui;
}
