
#include "Crear_usuario.h"
#include <QMessageBox>
#include "types.h"
#include <Cliente.h>
#include <DataStream.h>

Crear_usuario::Crear_usuario(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setWindowTitle("Crear Usuario");
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);
    cContrasenaLineEdit->setEchoMode(QLineEdit::Password);

    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(crear(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));

    _cliente = new Cliente(this);
    _cliente->start("127.0.0.1", PUERTO);
    connect(_cliente->client(), SIGNAL(connected(void)), this, SLOT(guardarUsuario()));
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

        QByteArray block;
        DataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_7);

        int p = NuevoUsuario;
        out << p;
        out << u;

        out.device()->seek(0);
        _cliente->client()->write(block);
        _cliente->client()->flush();

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

void Crear_usuario::guardarUsuario()
{

}