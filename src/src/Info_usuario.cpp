#include "Info_usuario.h"
#include "ui_Info_usuario.h"

Info_usuario::Info_usuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info_usuario)
{
    ui->setupUi(this);
}

Info_usuario::~Info_usuario()
{
    delete ui;
}
