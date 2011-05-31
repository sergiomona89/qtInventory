
#ifndef ADMINISTRACIONUSUARIO_H
#define ADMINISTRACIONUSUARIO_H

#include <QWidget>
#include"ui_administracion_usuario.h"

class AdministracionUsuario : public QDialog, Ui::administracion_usuario
{
Q_OBJECT
public:
    AdministracionUsuario(QWidget *parent = 0);
    ~AdministracionUsuario(void);

signals:

public slots:

};

#endif // ADMINISTRACIONUSUARIO_H
