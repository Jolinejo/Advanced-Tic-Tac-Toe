/********************************************************************************
** Form generated from reading UI file 'gameslist.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESLIST_H
#define UI_GAMESLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamesList
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QDialog *gamesList)
    {
        if (gamesList->objectName().isEmpty())
            gamesList->setObjectName("gamesList");
        gamesList->resize(436, 405);
        pushButton = new QPushButton(gamesList);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 320, 171, 32));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(gamesList);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(160, 70, 126, 18));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        listWidget = new QListWidget(gamesList);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(50, 100, 331, 211));

        retranslateUi(gamesList);

        QMetaObject::connectSlotsByName(gamesList);
    } // setupUi

    void retranslateUi(QDialog *gamesList)
    {
        gamesList->setWindowTitle(QCoreApplication::translate("gamesList", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("gamesList", "Replay Game", nullptr));
        label->setText(QCoreApplication::translate("gamesList", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("gamesList", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamesList: public Ui_gamesList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESLIST_H
