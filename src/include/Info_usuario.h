
#ifndef INFO_USUARIO_H
#define INFO_USUARIO_H

#include <QWidget>
#include "Usuario.h"
#include "ui_Info_usuario.h"

class Info_usuario : public QWidget, Ui::Info_usuario
{
    Q_OBJECT
public:
    Info_usuario(Usuario &usr, QWidget *parent = 0);
    ~Info_usuario();

    void setUsuario(Usuario &usr);
};

#endif // INFO_USUARIO_H
