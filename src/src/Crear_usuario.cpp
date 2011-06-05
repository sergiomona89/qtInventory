
#include "Crear_usuario.h"
#include <QMessageBox>

Crear_usuario::Crear_usuario(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setWindowTitle("Crear Usuario");
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);
    cContrasenaLineEdit->setEchoMode(QLineEdit::Password);

    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(crear(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
}

void Crear_usuario::crear()
{
    if(contrasenaLineEdit->text() == cContrasenaLineEdit->text())
    {
        Usuario u;
        u.setNombre( nombreLineEdit->text());
        u.setId(idLineEdit->text().toInt());
        u.setCargo(cargoLineEdit->text());
        u.setContrasena(contrasenaLineEdit->text());
        u.setEmail(emailLineEdit->text());
        u.setTelefono(telefonoLineEdit->text().toInt());

        if(DBQueries::guardarUsuario(u))
        {
            QMessageBox * si = new QMessageBox(this);
            si->setWindowTitle("Crear");
            si->setText(QString("El usuario se ha creado exitosamente"));
            si->show();
        }
        else
        {
            QMessageBox * error = new QMessageBox(this);
            error->setWindowTitle("Crear");
            error->setText(QString("No se pudo crear"));
            error->show();
        }

        accept();

    }
    else
    {
        QMessageBox * error = new QMessageBox(this);
        error->setWindowTitle("Error");
        error->setText(QString("Verificacion de contraseñas invalida"));
        error->show();
    }
}
