#include "Crear_usuario.h"


Crear_usuario::Crear_usuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crear_usuario)
{
    ui->setupUi(this);

    connect(ui->aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(crear()));
    connect(ui->cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(close()));
}

Crear_usuario::~Crear_usuario()
{
    delete ui;
}

void Crear_usuario::crear()
{
    Usuario u;
    u.setNombre( ui->nombreLineEdit->text());
    u.setId(ui->idLineEdit->text().toInt());
    u.setCargo(ui->cargoLineEdit->text());
    u.setContrasena(ui->contrasenaLineEdit->text());
    u.setEmail(ui->emailLineEdit->text());
    u.setTelefono(ui->telefonoLineEdit->text().toInt());

    if(DBQueries::guardarUsuario(u))
    {
#warning "falta mensaje de error"
    }
}
