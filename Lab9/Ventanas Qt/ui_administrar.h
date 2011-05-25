/********************************************************************************
** Form generated from reading UI file 'administrar.ui'
**
** Created: Tue May 24 01:53:47 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRAR_H
#define UI_ADMINISTRAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Administrar
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Administrar)
    {
        if (Administrar->objectName().isEmpty())
            Administrar->setObjectName(QString::fromUtf8("Administrar"));
        Administrar->resize(318, 179);
        widget = new QWidget(Administrar);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 212, 97));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 2, 3, 1);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        radioButton_3 = new QRadioButton(widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_2->addWidget(radioButton_3, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        radioButton->raise();
        radioButton_2->raise();
        radioButton_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton->raise();

        retranslateUi(Administrar);
        QObject::connect(pushButton, SIGNAL(clicked()), Administrar, SLOT(open()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Administrar, SLOT(open()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Administrar, SLOT(open()));

        QMetaObject::connectSlotsByName(Administrar);
    } // setupUi

    void retranslateUi(QDialog *Administrar)
    {
        Administrar->setWindowTitle(QApplication::translate("Administrar", "Administrar", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Administrar", "Usuario", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Administrar", "Consultar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Administrar", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Administrar", "Modificar", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Administrar", "Bodega", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Administrar", "Producto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Administrar: public Ui_Administrar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRAR_H
