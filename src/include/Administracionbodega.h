
#ifndef ADMINISTRACIONBODEGA_H
#define ADMINISTRACIONBODEGA_H

#include <QDialog>
#include"ui_Administracionbodega.h"
#include "DBQueries.h"

class AdministracionBodega : public QDialog, Ui::AdministracionBodega
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
};

#endif // ADMINISTRACIONBODEGA_H
