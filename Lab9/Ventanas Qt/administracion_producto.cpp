#ifndef PRODUCTOFV1706_H
#define PRODUCTOFV1706_H

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

class Ui_administracion_Producto
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QListWidget *list_Producto;
    QPushButton *Crear_Producto;
    QPushButton *Actualizar_Producto;
    QPushButton *Consultar_Producto;
    QPushButton *Eliminar_Producto;
    QPushButton *Cancelar_Producto;

    void setupUi(QDialog *administracion_Producto)
    {
        if (administracion_Producto->objectName().isEmpty())
            administracion_Producto->setObjectName(QString::fromUtf8("administracion_Producto"));
        administracion_Producto->resize(492, 255);
        layoutWidget = new QWidget(administracion_Producto);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 349, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        list_Producto = new QListWidget(layoutWidget);
        list_Producto->setObjectName(QString::fromUtf8("list_Producto"));

        gridLayout->addWidget(list_Producto, 0, 0, 5, 1);

        Crear_Producto = new QPushButton(layoutWidget);
        Crear_Producto->setObjectName(QString::fromUtf8("Crear_Producto"));

        gridLayout->addWidget(Crear_Producto, 0, 1, 1, 1);

        Actualizar_Producto = new QPushButton(layoutWidget);
        Actualizar_Producto->setObjectName(QString::fromUtf8("Actualizar_Producto"));

        gridLayout->addWidget(Actualizar_Producto, 1, 1, 1, 1);

        Consultar_Producto = new QPushButton(layoutWidget);
        Consultar_Producto->setObjectName(QString::fromUtf8("Consultar_Producto"));

        gridLayout->addWidget(Consultar_Producto, 2, 1, 1, 1);

        Eliminar_Producto = new QPushButton(layoutWidget);
        Eliminar_Producto->setObjectName(QString::fromUtf8("Eliminar_Producto"));

        gridLayout->addWidget(Eliminar_Producto, 3, 1, 1, 1);

        Cancelar_Producto = new QPushButton(layoutWidget);
        Cancelar_Producto->setObjectName(QString::fromUtf8("Cancelar_Producto"));

        gridLayout->addWidget(Cancelar_Producto, 4, 1, 1, 1);


        retranslateUi(administracion_Producto);

        QMetaObject::connectSlotsByName(administracion_Producto);
    } // setupUi

    void retranslateUi(QDialog *administracion_Producto)
    {
        administracion_Producto->setWindowTitle(QApplication::translate("administracion_Producto", "Administracion de Producto", 0, QApplication::UnicodeUTF8));
        Crear_Producto->setText(QApplication::translate("administracion_Producto", "Crear", 0, QApplication::UnicodeUTF8));
        Actualizar_Producto->setText(QApplication::translate("administracion_Producto", "Actualizar", 0, QApplication::UnicodeUTF8));
        Consultar_Producto->setText(QApplication::translate("administracion_Producto", "Consultar", 0, QApplication::UnicodeUTF8));
        Eliminar_Producto->setText(QApplication::translate("administracion_Producto", "Eliminar ", 0, QApplication::UnicodeUTF8));
        Cancelar_Producto->setText(QApplication::translate("administracion_Producto", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class administracion_Producto: public Ui_administracion_Producto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRODUCTOFV1706_H

