#ifndef CONSULTA_INVENTARIO_H
#define CONSULTA_INVENTARIO_H

#include <QWidget>

namespace Ui {
    class Consulta_inventario;
}

class Consulta_inventario : public QWidget
{
    Q_OBJECT

public:
    explicit Consulta_inventario(QWidget *parent = 0);
    ~Consulta_inventario();

private:
    Ui::Consulta_inventario *ui;
};

#endif // CONSULTA_INVENTARIO_H
