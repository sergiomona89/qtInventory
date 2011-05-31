#include "Consulta_inventario.h"
#include "ui_Consulta_inventario.h"

Consulta_inventario::Consulta_inventario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Consulta_inventario)
{
    ui->setupUi(this);
}

Consulta_inventario::~Consulta_inventario()
{
    delete ui;
}
