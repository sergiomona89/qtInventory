
#ifndef CREAR_USUARIO_H
#define CREAR_USUARIO_H

#include <QDialog>
#include "Usuario.h"
#include "ui_Crear_usuario.h"
#include "DBQueries.h"

class Cliente;

class Crear_usuario : public QDialog, Ui::Crear_usuario
{
    Q_OBJECT
public:
    Crear_usuario(QWidget *parent = 0);

public slots:
    void crear(void);

protected:
    Cliente * _cliente;

protected slots:
    void guardarUsuario(void);
};

#endif // CREAR_USUARIO_H
