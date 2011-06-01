
#ifndef CREAR_USUARIO_H
#define CREAR_USUARIO_H

#include <QWidget>
#include "Usuario.h"
#include "ui_Crear_usuario.h"
#include "DBQueries.h"

namespace Ui {
    class Crear_usuario;
}

class Crear_usuario : public QWidget
{
    Q_OBJECT

public:
    Crear_usuario(QWidget *parent = 0);
    ~Crear_usuario();

private:
    Ui::Crear_usuario *ui;

public slots:
    void crear(void);
};

#endif // CREAR_USUARIO_H
