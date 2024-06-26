/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QPushButton *pushButton_playerxplayer;
    QPushButton *pushButton_AI;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QMenu *menuWelcome;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(821, 750);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-10, -50, 841, 1121));
        label_3->setMinimumSize(QSize(0, 681));
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(:/users/mainwindow.png)\n"
""));
        pushButton_playerxplayer = new QPushButton(centralwidget);
        pushButton_playerxplayer->setObjectName("pushButton_playerxplayer");
        pushButton_playerxplayer->setGeometry(QRect(210, 420, 381, 51));
        pushButton_playerxplayer->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
        pushButton_AI = new QPushButton(centralwidget);
        pushButton_AI->setObjectName("pushButton_AI");
        pushButton_AI->setGeometry(QRect(260, 580, 261, 41));
        pushButton_AI->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(310, 130, 161, 20));
        checkBox->setLayoutDirection(Qt::LeftToRight);
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 14pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 821, 19));
        menuWelcome = new QMenu(menubar);
        menuWelcome->setObjectName("menuWelcome");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuWelcome->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        label_3->setText(QString());
        pushButton_playerxplayer->setText(QCoreApplication::translate("MainWindow", "Player VS Player", nullptr));
        pushButton_AI->setText(QCoreApplication::translate("MainWindow", "Player VS AI", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Mute Sound", nullptr));
        menuWelcome->setTitle(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
