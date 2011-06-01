
#ifndef ADMINISTRACIONUSUARIO_H
#define ADMINISTRACIONUSUARIO_H

#include <QWidget>
#include"ui_AdministracionUsuario.h"

class AdministracionUsuario : public QDialog, Ui::AdministracionUsuario
{
    Q_OBJECT
public:
    AdministracionUsuario(QWidget *parent = 0);
    ~AdministracionUsuario(void);
};

#endif // ADMINISTRACIONUSUARIO_H
