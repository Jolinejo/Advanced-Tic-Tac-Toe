/********************************************************************************
** Form generated from reading UI file 'signin2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN2_H
#define UI_SIGNIN2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signin2
{
public:
    QLabel *label_4;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_username2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_password2;
    QPushButton *pushButton_login2;
    QCheckBox *checkBox_showpassword;
    QLabel *label_ifthere;
    QLabel *label_3;
    QPushButton *pushButton_signup2;

    void setupUi(QDialog *signin2)
    {
        if (signin2->objectName().isEmpty())
            signin2->setObjectName("signin2");
        signin2->resize(436, 405);
        label_4 = new QLabel(signin2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 451, 411));
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(:/users/signin.png)"));
        groupBox = new QGroupBox(signin2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 90, 231, 271));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"gridline-color: transparent;\n"
""));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 20, 231, 241));
        widget->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label);

        lineEdit_username2 = new QLineEdit(widget);
        lineEdit_username2->setObjectName("lineEdit_username2");

        horizontalLayout_3->addWidget(lineEdit_username2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);

        lineEdit_password2 = new QLineEdit(widget);
        lineEdit_password2->setObjectName("lineEdit_password2");

        horizontalLayout->addWidget(lineEdit_password2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_login2 = new QPushButton(widget);
        pushButton_login2->setObjectName("pushButton_login2");
        pushButton_login2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_login2);

        checkBox_showpassword = new QCheckBox(widget);
        checkBox_showpassword->setObjectName("checkBox_showpassword");
        checkBox_showpassword->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(checkBox_showpassword);

        label_ifthere = new QLabel(widget);
        label_ifthere->setObjectName("label_ifthere");
        label_ifthere->setMinimumSize(QSize(0, 5));
        label_ifthere->setMaximumSize(QSize(16777215, 15));
        label_ifthere->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout_2->addWidget(label_ifthere);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 10));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_3);

        pushButton_signup2 = new QPushButton(widget);
        pushButton_signup2->setObjectName("pushButton_signup2");
        pushButton_signup2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_signup2);


        retranslateUi(signin2);

        QMetaObject::connectSlotsByName(signin2);
    } // setupUi

    void retranslateUi(QDialog *signin2)
    {
        signin2->setWindowTitle(QCoreApplication::translate("signin2", "Dialog", nullptr));
        label_4->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("signin2", "Sign in", nullptr));
        label->setText(QCoreApplication::translate("signin2", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("signin2", "Password", nullptr));
        pushButton_login2->setText(QCoreApplication::translate("signin2", "Login", nullptr));
        checkBox_showpassword->setText(QCoreApplication::translate("signin2", "show password", nullptr));
        label_ifthere->setText(QString());
        label_3->setText(QCoreApplication::translate("signin2", "Don't have account!", nullptr));
        pushButton_signup2->setText(QCoreApplication::translate("signin2", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin2: public Ui_signin2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN2_H
