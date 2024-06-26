/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

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

class Ui_signin
{
public:
    QLabel *label_6;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QCheckBox *checkBox_showpassword;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *pushButton_signup1;

    void setupUi(QDialog *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName("signin");
        signin->resize(436, 405);
        signin->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(signin);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 0, 461, 421));
        label_6->setStyleSheet(QString::fromUtf8("background-image:url(:/users/signin.png)"));
        groupBox = new QGroupBox(signin);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 90, 231, 271));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 20, 231, 241));
        widget->setStyleSheet(QString::fromUtf8("\n"
"background-color:transparent"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        lineEdit_username = new QLineEdit(widget);
        lineEdit_username->setObjectName("lineEdit_username");

        horizontalLayout_3->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(lineEdit_password);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton_login = new QPushButton(widget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_login);

        checkBox_showpassword = new QCheckBox(widget);
        checkBox_showpassword->setObjectName("checkBox_showpassword");

        verticalLayout_2->addWidget(checkBox_showpassword);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 10));

        verticalLayout_2->addWidget(label_3);

        pushButton_signup1 = new QPushButton(widget);
        pushButton_signup1->setObjectName("pushButton_signup1");
        pushButton_signup1->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_signup1);


        retranslateUi(signin);

        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QDialog *signin)
    {
        signin->setWindowTitle(QCoreApplication::translate("signin", "Dialog", nullptr));
        label_6->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("signin", "Sign in", nullptr));
        label->setText(QCoreApplication::translate("signin", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("signin", "Password ", nullptr));
        pushButton_login->setText(QCoreApplication::translate("signin", "Login", nullptr));
        checkBox_showpassword->setText(QCoreApplication::translate("signin", "show password", nullptr));
        label_4->setText(QString());
        label_3->setText(QCoreApplication::translate("signin", "Dont't have account!", nullptr));
        pushButton_signup1->setText(QCoreApplication::translate("signin", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
