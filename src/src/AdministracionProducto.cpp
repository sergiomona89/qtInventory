
// Qt
#include <QInputDialog>

#include "Act_producto.h"
#include "AdministracionProducto.h"
#include "Crear_producto.h"
#include "types.h"

AdministracionProducto::AdministracionProducto(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(NuevoPushButton, SIGNAL(clicked(void)), this, SLOT(nuevoProducto(void)));
    connect(ActualizarPushButton, SIGNAL(clicked(void)), this, SLOT(actualizarProducto(void)));
    connect(EliminarPushButton, SIGNAL(clicked(void)), this, SLOT(eliminarProducto(void)));

    QStringList lst;
    lst << "Numero Unico" << "Referencia" << "Descripcion" << "Bodega" << "Precio compra" << "Precio venta";

    ProductosTreeWidget->setHeaderLabels(lst);

    ProductoList * pl = DBQueries::productos();
    setProductos(pl);
    delete pl;
}

void AdministracionProducto::setProductos(ProductoList * lst)
{
    ProductosTreeWidget->clear();
    for(ProductoListIterator it = lst->begin(); it != lst->end(); it++)
    {
      
      //
      
      //
        Producto * pdt = &(*it);
        QTreeWidgetItem * item = new QTreeWidgetItem(ProductosTreeWidget);
        item->setText(0, QString::number(pdt->getId()));
	item->setText(1, pdt->getNombre());
	item->setText(2, pdt->getDescripcion());
	print(pdt->getBodega().toInt());
	Bodega * bdg = DBQueries::bodega(pdt->getBodega().toInt());
 	item->setText(3, bdg->getNombre());
 	item->setText(4, pdt->getPrecioCompra());
 	item->setText(5,pdt->getPrecioVenta());
    }
    print("paso");
}

void AdministracionProducto::nuevoProducto()
{
    Crear_producto cp(this);
    if(cp.exec() == QDialog::Accepted)
    {
        ProductoList * pl = DBQueries::productos();
        setProductos(pl);
        delete pl;
    }
}

void AdministracionProducto::actualizarProducto()
{
  
    QInputDialog id(this);
    id.setLabelText("Ingrese el numero unico del producto a actualizar");
    if(id.exec() == QDialog::Accepted)
    {
      
      //el esta escojiendo el currentIndex del combobox y no el indice de la bodega.
        Producto * pdt = DBQueries::producto(id.textValue().toInt());
        if(pdt == 0)
            return;
	
        Act_producto ap(pdt->getId(),pdt->getNombre(), pdt->getDescripcion(),pdt->getBodega(),pdt->getPrecioCompra(), pdt->getPrecioVenta(), this);
	print("llega aqui3");
	print(ap.exec());//aqui hay fallo de segmentacion.
        if(ap.exec() == QDialog::Accepted)
        {
            ProductoList * pl = DBQueries::productos();
            setProductos(pl);
            delete pl;
        }
        delete pdt;
    }
}

void AdministracionProducto::eliminarProducto()
{
    QInputDialog id(this);
    id.setLabelText("Ingrese el numero unico del producto a eliminar");
    if(id.exec() == QDialog::Accepted)
    {
        DBQueries::eliminarProducto(id.textValue().toInt());

        ProductoList * pl = DBQueries::productos();
        setProductos(pl);
        delete pl;
    }
}