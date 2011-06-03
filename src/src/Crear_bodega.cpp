#include "Crear_bodega.h"
#include "ui_Crear_bodega.h"

Crear_bodega::Crear_bodega(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crear_bodega)
{
    ui->setupUi(this);
}

Crear_bodega::~Crear_bodega()
{
    delete ui;
}
