
#include "Crear_producto.h"
#include <QMessageBox>

Crear_producto::Crear_producto(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    
    setWindowTitle("Crear Producto");
    
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
    
    connect(aceptarPushButton, SIGNAL(clicked(void)), this, SLOT(crear(void)));
    connect(cancelarPushButton, SIGNAL(clicked(void)), this, SLOT(reject(void)));
}

void Crear_producto::crear()
{
            Producto p;
            p.setNombre(referenciaLineEdit->text());
            p.setDescripcion(descripcionTextEdit->toPlainText());
	    int i = bodegaComboBox->currentIndex();
	    
            p.setBodega(QString::number(indBodega[i]));
            p.setPrecioCompra(precioCompraLineEdit->text());
            p.setPrecioVenta(precioVentaLineEdit->text());

            if(DBQueries::guardarProducto(p))
            {
                QMessageBox * si = new QMessageBox(this);
                si->setWindowTitle("Agregar");
                si->setText(QString("El producto se ha agregado exitosamente"));
                si->show();
            }
            else
            {
                QMessageBox * error = new QMessageBox(this);
                error->setWindowTitle("Agregar");
                error->setText(QString("No se pudo agregar"));
                error->show();
            }

            accept();
}
