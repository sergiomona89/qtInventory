#ifndef BODEGADT1862_H
#define BODEGADT1862_H

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

class Ui_administracion_Bodega
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QListWidget *list_Bodega;
    QPushButton *Crear_Bodega;
    QPushButton *Actualizar_Bodega;
    QPushButton *Consultar_Bodega;
    QPushButton *Eliminar_Bodega;
    QPushButton *Cancelar_Bodega;

    void setupUi(QDialog *administracion_Bodega)
    {
        if (administracion_Bodega->objectName().isEmpty())
            administracion_Bodega->setObjectName(QString::fromUtf8("administracion_Bodega"));
        administracion_Bodega->resize(492, 255);
        layoutWidget = new QWidget(administracion_Bodega);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 349, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        list_Bodega = new QListWidget(layoutWidget);
        list_Bodega->setObjectName(QString::fromUtf8("list_Bodega"));

        gridLayout->addWidget(list_Bodega, 0, 0, 5, 1);

        Crear_Bodega = new QPushButton(layoutWidget);
        Crear_Bodega->setObjectName(QString::fromUtf8("Crear_Bodega"));

        gridLayout->addWidget(Crear_Bodega, 0, 1, 1, 1);

        Actualizar_Bodega = new QPushButton(layoutWidget);
        Actualizar_Bodega->setObjectName(QString::fromUtf8("Actualizar_Bodega"));

        gridLayout->addWidget(Actualizar_Bodega, 1, 1, 1, 1);

        Consultar_Bodega = new QPushButton(layoutWidget);
        Consultar_Bodega->setObjectName(QString::fromUtf8("Consultar_Bodega"));

        gridLayout->addWidget(Consultar_Bodega, 2, 1, 1, 1);

        Eliminar_Bodega = new QPushButton(layoutWidget);
        Eliminar_Bodega->setObjectName(QString::fromUtf8("Eliminar_Bodega"));

        gridLayout->addWidget(Eliminar_Bodega, 3, 1, 1, 1);

        Cancelar_Bodega = new QPushButton(layoutWidget);
        Cancelar_Bodega->setObjectName(QString::fromUtf8("Cancelar_Bodega"));

        gridLayout->addWidget(Cancelar_Bodega, 4, 1, 1, 1);


        retranslateUi(administracion_Bodega);

        QMetaObject::connectSlotsByName(administracion_Bodega);
    } // setupUi

    void retranslateUi(QDialog *administracion_Bodega)
    {
        administracion_Bodega->setWindowTitle(QApplication::translate("administracion_Bodega", "Administracion de bodega", 0, QApplication::UnicodeUTF8));
        Crear_Bodega->setText(QApplication::translate("administracion_Bodega", "Crear", 0, QApplication::UnicodeUTF8));
        Actualizar_Bodega->setText(QApplication::translate("administracion_Bodega", "Actualizar", 0, QApplication::UnicodeUTF8));
        Consultar_Bodega->setText(QApplication::translate("administracion_Bodega", "Consultar", 0, QApplication::UnicodeUTF8));
        Eliminar_Bodega->setText(QApplication::translate("administracion_Bodega", "Eliminar ", 0, QApplication::UnicodeUTF8));
        Cancelar_Bodega->setText(QApplication::translate("administracion_Bodega", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class administracion_Bodega: public Ui_administracion_Bodega {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BODEGADT1862_H

