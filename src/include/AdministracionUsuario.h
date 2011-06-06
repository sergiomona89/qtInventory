

#ifndef ADMINISTRACIONUSUARIO_H
#define ADMINISTRACIONUSUARIO_H

#include <QWidget>
#include "ui_AdministracionUsuario.h"
#include "DBQueries.h"

class Cliente;

class AdministracionUsuario : public QWidget, Ui::AdministracionUsuario
{
    Q_OBJECT
public:
    AdministracionUsuario(QWidget *parent = 0);
    ~AdministracionUsuario(void) {}

    void setUsuarios(UsuarioList * lst);

public slots:
    void nuevoUsuario(void);
    void actualizarUsuario(void);
    void eliminarUsuario(void);

protected:
    Cliente * _cliente;

protected slots:
    void descargarUsuarios(void);
    void startRead(void);
};

#endif // ADMINISTRACIONUSUARIO_H
