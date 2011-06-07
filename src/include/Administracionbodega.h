
#ifndef ADMINISTRACIONBODEGA_H
#define ADMINISTRACIONBODEGA_H

#include <QWidget>
#include"ui_Administracionbodega.h"
#include "DBQueries.h"

class Cliente;

class AdministracionBodega : public QWidget, Ui::AdministracionBodega
{
    Q_OBJECT
public:
    AdministracionBodega(QWidget *parent = 0);
    ~AdministracionBodega(void) {}

    void setBodegas(BodegaList * lst);

public slots:
    void nuevaBodega(void);
    void actualizarBodega(void);
    void eliminarBodega(void);

protected:
    Cliente * _cliente;

protected slots:
    void descargarBodegas(void);
    void startRead(void);
};

#endif // ADMINISTRACIONBODEGA_H
