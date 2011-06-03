
#ifndef CREAR_USUARIO_H
#define CREAR_USUARIO_H

#include <QDialog>
#include "Usuario.h"
#include "ui_Crear_usuario.h"
#include "DBQueries.h"

class Crear_usuario : public QDialog, Ui::Crear_usuario
{
    Q_OBJECT

public:
    Crear_usuario(QWidget *parent = 0);

public slots:
    void crear(void);
};

#endif // CREAR_USUARIO_H
