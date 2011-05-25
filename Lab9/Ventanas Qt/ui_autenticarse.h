/********************************************************************************
** Form generated from reading UI file 'autenticarse.ui'
**
** Created: Tue May 24 01:53:47 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTENTICARSE_H
#define UI_AUTENTICARSE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Autenticacion
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Autenticacion)
    {
        if (Autenticacion->objectName().isEmpty())
            Autenticacion->setObjectName(QString::fromUtf8("Autenticacion"));
        Autenticacion->resize(372, 207);
        widget = new QWidget(Autenticacion);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(71, 52, 236, 95));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 2);

        QWidget::setTabOrder(lineEdit, lineEdit_2);

        retranslateUi(Autenticacion);
        QObject::connect(buttonBox, SIGNAL(accepted()), Autenticacion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Autenticacion, SLOT(reject()));

        QMetaObject::connectSlotsByName(Autenticacion);
    } // setupUi

    void retranslateUi(QDialog *Autenticacion)
    {
        Autenticacion->setWindowTitle(QApplication::translate("Autenticacion", "Autenticacion", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Autenticacion", "Usuario", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Autenticacion", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setInputMask(QApplication::translate("Autenticacion", "*; ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Autenticacion: public Ui_Autenticacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTENTICARSE_H
