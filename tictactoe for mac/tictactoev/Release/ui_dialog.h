/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_display1;
    QPushButton *pushButton_display2;
    QPushButton *pushButton_2;
    QCheckBox *AiFirst;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(436, 405);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 70, 341, 61));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Segoe UI\";"));
        pushButton_display1 = new QPushButton(Dialog);
        pushButton_display1->setObjectName("pushButton_display1");
        pushButton_display1->setGeometry(QRect(40, 140, 341, 41));
        pushButton_display1->setStyleSheet(QString::fromUtf8("font: 700 15pt \"Segoe UI\";"));
        pushButton_display2 = new QPushButton(Dialog);
        pushButton_display2->setObjectName("pushButton_display2");
        pushButton_display2->setGeometry(QRect(40, 190, 341, 51));
        pushButton_display2->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Segoe UI\";"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 260, 81, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        AiFirst = new QCheckBox(Dialog);
        AiFirst->setObjectName("AiFirst");
        AiFirst->setGeometry(QRect(177, 200, 71, 31));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "start the game !", nullptr));
        pushButton_display1->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_display2->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Sign out", nullptr));
        AiFirst->setText(QCoreApplication::translate("Dialog", "Ai First?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
