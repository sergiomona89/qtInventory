
#include "Crear_bodega.h"
#include <QMessageBox>

Crear_bodega::Crear_bodega(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setWindowTitle("Crear Bodega");

    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(crear(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
}

void Crear_bodega::crear()
{
        Bodega bdg;
        bdg.setNombre( nombreLineEdit->text());
        bdg.setDireccion(ubicacionLineEdit->text());
        bdg.setDescripcion(descripcionTextEdit->toPlainText());
        bdg.setTelefono(telefonoLineEdit->text().toInt());

        if(DBQueries::guardarBodega(bdg))
        {
            QMessageBox * si = new QMessageBox(this);
            si->setWindowTitle("Crear");
            si->setText(QString("La bodega se ha creado exitosamente"));
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
