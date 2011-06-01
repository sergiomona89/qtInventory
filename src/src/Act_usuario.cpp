
#include "Act_usuario.h"
#include "DBQueries.h"

Act_usuario::Act_usuario(QString nombre, QString cargo, int id, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    NombreLineEdit->setText(nombre);
    CargoLineEdit->setText(cargo);
    IdLineEdit->setText(QString::number(id));

    connect(AceptarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizar(void)));
    connect(CancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
}

void Act_usuario::actualizar(void)
{
    if(ModificarCheckBox->checkState() == Qt::Checked)
    {
        DBQueries::actualizarUsuario(NombreLineEdit->text(), CargoLineEdit->text(), IdLineEdit->text().toInt(), NuevaContrasenaLineEdit->text());
    }
    else
    {
        DBQueries::actualizarUsuario(NombreLineEdit->text(), CargoLineEdit->text(), IdLineEdit->text().toInt());
    }

    accept();
}