
#include "Act_usuario.h"
#include "DBQueries.h"
#include <QMessageBox>

Act_usuario::Act_usuario(QString nombre, QString cargo, int id, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    NombreLineEdit->setText(nombre);
    CargoLineEdit->setText(cargo);
    IdLineEdit->setText(QString::number(id));
    ContrasenaLineEdit->setEchoMode(QLineEdit::Password);
    ContrasenaLineEdit->setEnabled(false);
    NuevaContrasenaLineEdit->setEchoMode(QLineEdit::Password);
    NuevaContrasenaLineEdit->setEnabled(false);
    ConfirmarContrasenaLineEdit->setEchoMode(QLineEdit::Password);
    ConfirmarContrasenaLineEdit->setEnabled(false);
    IdLineEdit->setEnabled(false);

    connect(AceptarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizar(void)));
    connect(CancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
    connect(ModificarCheckBox, SIGNAL(stateChanged(int)), this, SLOT(esChecked(void)));
}

void Act_usuario::esChecked()
{
    if(ModificarCheckBox->isChecked())
    {
        ContrasenaLineEdit->setEnabled(true);
        NuevaContrasenaLineEdit->setEnabled(true);
        ConfirmarContrasenaLineEdit->setEnabled(true);
    }
    else
    {
        ContrasenaLineEdit->setEnabled(false);
        NuevaContrasenaLineEdit->setEnabled(false);
        ConfirmarContrasenaLineEdit->setEnabled(false);
    }
}

void Act_usuario::actualizar(void)
{
    if(ModificarCheckBox->checkState() == Qt::Checked)
    {
       Usuario * u = DBQueries::usuario(IdLineEdit->text().toInt());
       if(u->getContrasena() == ContrasenaLineEdit->text())
       {
            if(NuevaContrasenaLineEdit->text() == ConfirmarContrasenaLineEdit->text())
            {
                DBQueries::actualizarUsuario(NombreLineEdit->text(), CargoLineEdit->text(), IdLineEdit->text().toInt(), NuevaContrasenaLineEdit->text());
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
       else
       {
           QMessageBox * error = new QMessageBox(this);
           error->setWindowTitle("Error");
           error->setText(QString("La contraseña es invalida"));
           error->show();
       }
    }
    else
    {
        DBQueries::actualizarUsuario(NombreLineEdit->text(), CargoLineEdit->text(), IdLineEdit->text().toInt());
        accept();
    }
}
