/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created: Tue May 24 01:53:47 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName(QString::fromUtf8("Interfaz"));
        Interfaz->resize(533, 296);
        widget = new QWidget(Interfaz);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 60, 131, 151));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);


        retranslateUi(Interfaz);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Interfaz, SLOT(open()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Interfaz, SLOT(open()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Interfaz, SLOT(open()));
        QObject::connect(pushButton, SIGNAL(clicked()), Interfaz, SLOT(open()));

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QDialog *Interfaz)
    {
        Interfaz->setWindowTitle(QApplication::translate("Interfaz", "Software Inventario", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Interfaz", "Entradas", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Interfaz", "Salidas", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Interfaz", "Inventario", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Interfaz", "Administrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
