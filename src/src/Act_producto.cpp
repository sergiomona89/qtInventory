
#include "Act_producto.h"
#include "DBQueries.h"
#include "types.h"

Act_producto::Act_producto(int id, QString nombre, QString descripcion, QString bodega, QString precioCompra, QString precioVenta, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    idLabel->setText(QString::number(id));
    referenciaLineEdit->setText(nombre);
    descripcionTextEdit->setText(descripcion);
    BodegaList * bl = DBQueries::bodegas();
    indBodega[bl->count()];
    int i = 0;
    for(BodegaListIterator it = bl->begin(); it != bl->end(); it++)
    {
      Bodega * bdg = &(*it);
      bodegaComboBox->addItem(bdg->getNombre(), bdg->getId());
      indBodega[i] = bdg->getId();
      i++;
    }
    bodegaComboBox->itemText(bodega.toInt());
    precioCompraLineEdit->setText(precioCompra);
    precioVentaLineEdit->setText(precioVenta);

    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizar(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
    print("llega aqui2");
}

void Act_producto::actualizar(void)
{
    DBQueries::actualizarProducto(idLabel->text().toInt(), referenciaLineEdit->text(), descripcionTextEdit->toPlainText(), QString::number(bodegaComboBox->currentIndex()), precioCompraLineEdit->text(), precioVentaLineEdit->text());
    accept();
}