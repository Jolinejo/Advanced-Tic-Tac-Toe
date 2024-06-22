/********************************************************************************
** Form generated from reading UI file 'startgame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTGAME_H
#define UI_STARTGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startgame {
 public:
  QLabel *label_p1;
  QLabel *label_p2;
  QWidget *gridLayoutWidget;
  QGridLayout *gridLayout_play;
  QPushButton *pushButton_10;
  QPushButton *pushButton_11;
  QPushButton *pushButton_12;
  QPushButton *pushButton_13;
  QPushButton *pushButton_14;
  QPushButton *pushButton_15;
  QPushButton *pushButton_16;
  QPushButton *pushButton_17;
  QPushButton *pushButton_18;
  QLCDNumber *lcdNumber_p1;
  QLCDNumber *lcdNumber_p2;
  QLabel *label_round;
  QCheckBox *checkBox;

  void setupUi(QDialog *Startgame) {
    if (Startgame->objectName().isEmpty())
      Startgame->setObjectName("Startgame");
    Startgame->resize(400, 321);
    label_p1 = new QLabel(Startgame);
    label_p1->setObjectName("label_p1");
    label_p1->setGeometry(QRect(10, 20, 81, 16));
    label_p1->setAlignment(Qt::AlignCenter);
    label_p2 = new QLabel(Startgame);
    label_p2->setObjectName("label_p2");
    label_p2->setGeometry(QRect(320, 20, 71, 16));
    label_p2->setAlignment(Qt::AlignCenter);
    gridLayoutWidget = new QWidget(Startgame);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(70, 50, 252, 231));
    gridLayout_play = new QGridLayout(gridLayoutWidget);
    gridLayout_play->setObjectName("gridLayout_play");
    gridLayout_play->setContentsMargins(0, 0, 0, 0);
    pushButton_10 = new QPushButton(gridLayoutWidget);
    pushButton_10->setObjectName("pushButton_10");
    QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum,
                           QSizePolicy::Policy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(
        pushButton_10->sizePolicy().hasHeightForWidth());
    pushButton_10->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_10, 2, 2, 1, 1);

    pushButton_11 = new QPushButton(gridLayoutWidget);
    pushButton_11->setObjectName("pushButton_11");
    sizePolicy.setHeightForWidth(
        pushButton_11->sizePolicy().hasHeightForWidth());
    pushButton_11->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_11, 1, 1, 1, 1);

    pushButton_12 = new QPushButton(gridLayoutWidget);
    pushButton_12->setObjectName("pushButton_12");
    sizePolicy.setHeightForWidth(
        pushButton_12->sizePolicy().hasHeightForWidth());
    pushButton_12->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_12, 1, 2, 1, 1);

    pushButton_13 = new QPushButton(gridLayoutWidget);
    pushButton_13->setObjectName("pushButton_13");
    sizePolicy.setHeightForWidth(
        pushButton_13->sizePolicy().hasHeightForWidth());
    pushButton_13->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_13, 1, 0, 1, 1);

    pushButton_14 = new QPushButton(gridLayoutWidget);
    pushButton_14->setObjectName("pushButton_14");
    sizePolicy.setHeightForWidth(
        pushButton_14->sizePolicy().hasHeightForWidth());
    pushButton_14->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_14, 2, 1, 1, 1);

    pushButton_15 = new QPushButton(gridLayoutWidget);
    pushButton_15->setObjectName("pushButton_15");
    sizePolicy.setHeightForWidth(
        pushButton_15->sizePolicy().hasHeightForWidth());
    pushButton_15->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_15, 2, 0, 1, 1);

    pushButton_16 = new QPushButton(gridLayoutWidget);
    pushButton_16->setObjectName("pushButton_16");
    sizePolicy.setHeightForWidth(
        pushButton_16->sizePolicy().hasHeightForWidth());
    pushButton_16->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_16, 0, 1, 1, 1);

    pushButton_17 = new QPushButton(gridLayoutWidget);
    pushButton_17->setObjectName("pushButton_17");
    sizePolicy.setHeightForWidth(
        pushButton_17->sizePolicy().hasHeightForWidth());
    pushButton_17->setSizePolicy(sizePolicy);
    pushButton_17->setStyleSheet(QString::fromUtf8(""));

    gridLayout_play->addWidget(pushButton_17, 0, 0, 1, 1);

    pushButton_18 = new QPushButton(gridLayoutWidget);
    pushButton_18->setObjectName("pushButton_18");
    sizePolicy.setHeightForWidth(
        pushButton_18->sizePolicy().hasHeightForWidth());
    pushButton_18->setSizePolicy(sizePolicy);

    gridLayout_play->addWidget(pushButton_18, 0, 2, 1, 1);

    lcdNumber_p1 = new QLCDNumber(Startgame);
    lcdNumber_p1->setObjectName("lcdNumber_p1");
    lcdNumber_p1->setGeometry(QRect(0, 50, 64, 23));
    lcdNumber_p2 = new QLCDNumber(Startgame);
    lcdNumber_p2->setObjectName("lcdNumber_p2");
    lcdNumber_p2->setGeometry(QRect(330, 50, 64, 23));
    label_round = new QLabel(Startgame);
    label_round->setObjectName("label_round");
    label_round->setGeometry(QRect(150, 10, 111, 20));
    QFont font;
    font.setPointSize(13);
    label_round->setFont(font);
    label_round->setAutoFillBackground(false);
    label_round->setAlignment(Qt::AlignCenter);
    checkBox = new QCheckBox(Startgame);
    checkBox->setObjectName("checkBox");
    checkBox->setGeometry(QRect(70, 290, 251, 20));
    checkBox->setLayoutDirection(Qt::LeftToRight);
    checkBox->setAutoFillBackground(false);
    checkBox->setChecked(false);

    retranslateUi(Startgame);

    QMetaObject::connectSlotsByName(Startgame);
  }  // setupUi

  void retranslateUi(QDialog *Startgame) {
    Startgame->setWindowTitle(
        QCoreApplication::translate("Startgame", "Dialog", nullptr));
    label_p1->setText(
        QCoreApplication::translate("Startgame", "TextLabel", nullptr));
    label_p2->setText(
        QCoreApplication::translate("Startgame", "TextLabel", nullptr));
    pushButton_10->setText(QString());
    pushButton_11->setText(QString());
    pushButton_12->setText(QString());
    pushButton_13->setText(QString());
    pushButton_14->setText(QString());
    pushButton_15->setText(QString());
    pushButton_16->setText(QString());
    pushButton_17->setText(QString());
#if QT_CONFIG(tooltip)
    pushButton_18->setToolTip(QCoreApplication::translate(
        "Startgame",
        "<html><head/><body><p "
        "align=\"center\">\330\247\330\250\330\272\330\247</p></body></html>",
        nullptr));
#endif  // QT_CONFIG(tooltip)
    pushButton_18->setText(QString());
    label_round->setText(
        QCoreApplication::translate("Startgame", "TextLabel", nullptr));
    checkBox->setText(QCoreApplication::translate(
        "Startgame", "Do you want to save these rounds? ", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Startgame : public Ui_Startgame {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_STARTGAME_H
