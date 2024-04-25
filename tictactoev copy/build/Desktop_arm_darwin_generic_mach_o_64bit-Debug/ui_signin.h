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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_signin
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QLabel *label_3;
    QPushButton *pushButton_signup1;

    void setupUi(QDialog *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName("signin");
        signin->resize(400, 300);
        groupBox = new QGroupBox(signin);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(120, 40, 231, 211));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName("lineEdit_username");

        horizontalLayout_3->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");

        verticalLayout_2->addWidget(pushButton_login);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        pushButton_signup1 = new QPushButton(groupBox);
        pushButton_signup1->setObjectName("pushButton_signup1");

        verticalLayout_2->addWidget(pushButton_signup1);


        retranslateUi(signin);

        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QDialog *signin)
    {
        signin->setWindowTitle(QCoreApplication::translate("signin", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signin", "Player1 SignIn", nullptr));
        label->setText(QCoreApplication::translate("signin", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("signin", "Password", nullptr));
        pushButton_login->setText(QCoreApplication::translate("signin", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("signin", "Dont't have account!", nullptr));
        pushButton_signup1->setText(QCoreApplication::translate("signin", "sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
