
#ifndef ADMINISTRACIONUSUARIO_H
#define ADMINISTRACIONUSUARIO_H

#include <QWidget>
#include "ui_AdministracionUsuario.h"
#include "DBQueries.h"

class AdministracionUsuario : public QDialog, Ui::AdministracionUsuario
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
};

#endif // ADMINISTRACIONUSUARIO_H
