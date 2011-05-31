#ifndef INFO_USUARIO_H
#define INFO_USUARIO_H

#include <QWidget>

namespace Ui {
    class Info_usuario;
}

class Info_usuario : public QWidget
{
    Q_OBJECT

public:
    explicit Info_usuario(QWidget *parent = 0);
    ~Info_usuario();

private:
    Ui::Info_usuario *ui;
};

#endif // INFO_USUARIO_H
