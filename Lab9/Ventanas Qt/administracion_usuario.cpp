
#ifndef USUARIOZK1530_H
#define USUARIOZK1530_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administracion_usuario
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QListWidget *list_usua;
    QPushButton *Crear_usuario;
    QPushButton *Actualizar_usuario;
    QPushButton *Consultar_usuario;
    QPushButton *Eliminar_usuario;
    QPushButton *Cancelar_usuario;

    void setupUi(QDialog *administracion_usuario)
    {
        if (administracion_usuario->objectName().isEmpty())
            administracion_usuario->setObjectName(QString::fromUtf8("administracion_usuario"));
        administracion_usuario->resize(492, 255);
        layoutWidget = new QWidget(administracion_usuario);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 349, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        list_usua = new QListWidget(layoutWidget);
        list_usua->setObjectName(QString::fromUtf8("list_usua"));

        gridLayout->addWidget(list_usua, 0, 0, 5, 1);

        Crear_usuario = new QPushButton(layoutWidget);
        Crear_usuario->setObjectName(QString::fromUtf8("Crear_usuario"));

        gridLayout->addWidget(Crear_usuario, 0, 1, 1, 1);

        Actualizar_usuario = new QPushButton(layoutWidget);
        Actualizar_usuario->setObjectName(QString::fromUtf8("Actualizar_usuario"));

        gridLayout->addWidget(Actualizar_usuario, 1, 1, 1, 1);

        Consultar_usuario = new QPushButton(layoutWidget);
        Consultar_usuario->setObjectName(QString::fromUtf8("Consultar_usuario"));

        gridLayout->addWidget(Consultar_usuario, 2, 1, 1, 1);

        Eliminar_usuario = new QPushButton(layoutWidget);
        Eliminar_usuario->setObjectName(QString::fromUtf8("Eliminar_usuario"));

        gridLayout->addWidget(Eliminar_usuario, 3, 1, 1, 1);

        Cancelar_usuario = new QPushButton(layoutWidget);
        Cancelar_usuario->setObjectName(QString::fromUtf8("Cancelar_usuario"));

        gridLayout->addWidget(Cancelar_usuario, 4, 1, 1, 1);


        retranslateUi(administracion_usuario);

        QMetaObject::connectSlotsByName(administracion_usuario);
    } // setupUi

    void retranslateUi(QDialog *administracion_usuario)
    {
        administracion_usuario->setWindowTitle(QApplication::translate("administracion_usuario", "Administracion de usuario", 0, QApplication::UnicodeUTF8));
        Crear_usuario->setText(QApplication::translate("administracion_usuario", "Crear", 0, QApplication::UnicodeUTF8));
        Actualizar_usuario->setText(QApplication::translate("administracion_usuario", "Actualizar", 0, QApplication::UnicodeUTF8));
        Consultar_usuario->setText(QApplication::translate("administracion_usuario", "Consultar", 0, QApplication::UnicodeUTF8));
        Eliminar_usuario->setText(QApplication::translate("administracion_usuario", "Eliminar ", 0, QApplication::UnicodeUTF8));
        Cancelar_usuario->setText(QApplication::translate("administracion_usuario", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class administracion_usuario: public Ui_administracion_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // USUARIOZK1530_H

