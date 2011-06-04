
#ifndef ACT_BODEGA_H
#define ACT_BODEGA_H

#include <QDialog>
#include "ui_Act_bodega.h"

class Act_bodega : public QDialog, Ui::Act_bodega
{
    Q_OBJECT

public:
    Act_bodega(QString nombre, QString direccion, QString descripcion, int telefono, int id, QWidget *parent = 0);

protected slots:
    void actualizar(void);
};

#endif // ACT_BODEGA_H
