#ifndef ACT_USUARIO_H
#define ACT_USUARIO_H

#include <QWidget>

namespace Ui {
class Act_usuario;
}

class Act_usuario : public QWidget
{
    Q_OBJECT

public:
    explicit Act_usuario(QWidget *parent = 0);
    ~Act_usuario();

private:
    Ui::Act_usuario *ui;
};

#endif // ACT_USUARIO_H
