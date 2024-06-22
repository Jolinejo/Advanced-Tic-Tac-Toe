/********************************************************************************
** Form generated from reading UI file 'gamehistory.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHISTORY_H
#define UI_GAMEHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameHistory
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridOfMoves;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_1;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSplitter *splitter;
    QPushButton *pushButton_play;
    QLabel *label_of_winner;

    void setupUi(QDialog *gameHistory)
    {
        if (gameHistory->objectName().isEmpty())
            gameHistory->setObjectName("gameHistory");
        gameHistory->resize(400, 300);
        gridLayoutWidget = new QWidget(gameHistory);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(19, 49, 351, 231));
        gridOfMoves = new QGridLayout(gridLayoutWidget);
        gridOfMoves->setObjectName("gridOfMoves");
        gridOfMoves->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_4, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_2, 0, 1, 1, 1);

        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName("label_1");
        label_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_1, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_6, 1, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_3, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_5, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_8, 2, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 255); /* Blue color */"));

        gridOfMoves->addWidget(label_9, 2, 2, 1, 1);

        splitter = new QSplitter(gameHistory);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 10, 351, 32));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_play = new QPushButton(splitter);
        pushButton_play->setObjectName("pushButton_play");
        splitter->addWidget(pushButton_play);
        label_of_winner = new QLabel(splitter);
        label_of_winner->setObjectName("label_of_winner");
        label_of_winner->setEnabled(true);
        splitter->addWidget(label_of_winner);

        retranslateUi(gameHistory);

        QMetaObject::connectSlotsByName(gameHistory);
    } // setupUi

    void retranslateUi(QDialog *gameHistory)
    {
        gameHistory->setWindowTitle(QCoreApplication::translate("gameHistory", "Dialog", nullptr));
        label_4->setText(QString());
        label_2->setText(QString());
        label_1->setText(QString());
        label_6->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        pushButton_play->setText(QCoreApplication::translate("gameHistory", "Play", nullptr));
        label_of_winner->setText(QCoreApplication::translate("gameHistory", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameHistory: public Ui_gameHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHISTORY_H
