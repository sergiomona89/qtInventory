
#ifndef ACT_USUARIO_H
#define ACT_USUARIO_H

#include <QWidget>
#include "ui_Act_usuario.h"

class Act_usuario : public QDialog, Ui::Act_usuario
{
    Q_OBJECT
public:
    Act_usuario(QString nombre, QString cargo, int id, QWidget *parent = 0);

protected slots:
    void actualizar(void);
    void esChecked(void);
};

#endif // ACT_USUARIO_H
