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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_signin2
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_username2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_password2;
    QPushButton *pushButton_login2;
    QLabel *label_3;
    QPushButton *pushButton_signup2;

    void setupUi(QDialog *signin2)
    {
        if (signin2->objectName().isEmpty())
            signin2->setObjectName("signin2");
        signin2->resize(400, 300);
        groupBox = new QGroupBox(signin2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 60, 211, 201));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        lineEdit_username2 = new QLineEdit(groupBox);
        lineEdit_username2->setObjectName("lineEdit_username2");

        horizontalLayout_3->addWidget(lineEdit_username2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_password2 = new QLineEdit(groupBox);
        lineEdit_password2->setObjectName("lineEdit_password2");

        horizontalLayout->addWidget(lineEdit_password2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_login2 = new QPushButton(groupBox);
        pushButton_login2->setObjectName("pushButton_login2");

        verticalLayout_2->addWidget(pushButton_login2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        pushButton_signup2 = new QPushButton(groupBox);
        pushButton_signup2->setObjectName("pushButton_signup2");

        verticalLayout_2->addWidget(pushButton_signup2);


        retranslateUi(signin2);

        QMetaObject::connectSlotsByName(signin2);
    } // setupUi

    void retranslateUi(QDialog *signin2)
    {
        signin2->setWindowTitle(QCoreApplication::translate("signin2", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signin2", "Player2 SignIn", nullptr));
        label->setText(QCoreApplication::translate("signin2", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("signin2", "Password", nullptr));
        pushButton_login2->setText(QCoreApplication::translate("signin2", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("signin2", "Don't have account!", nullptr));
        pushButton_signup2->setText(QCoreApplication::translate("signin2", "Sin up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin2: public Ui_signin2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN2_H
