
#include "Act_bodega.h"
#include "DBQueries.h"
#include <QMessageBox>

Act_bodega::Act_bodega(QString nombre, QString direccion, QString descripcion, int telefono, int id, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    nombreLineEdit->setText(nombre);
    ubicacionLineEdit->setText(direccion);
    descripcionTextEdit->setPlainText(descripcion);
    telefonoLineEdit->setText(QString::number(telefono));
    idLabel->setText(QString::number(id));

    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizar(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
}

void Act_bodega::actualizar(void)
{
       DBQueries::actualizarBodega(idLabel->text().toInt(), nombreLineEdit->text(), ubicacionLineEdit->text(), telefonoLineEdit->text().toInt(), descripcionTextEdit->toPlainText());
       accept();
}
