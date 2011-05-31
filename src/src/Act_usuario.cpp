#include "Act_usuario.h"
#include "ui_Act_usuario.h"

Act_usuario::Act_usuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Act_usuario)
{
    ui->setupUi(this);
}

Act_usuario::~Act_usuario()
{
    delete ui;
}
