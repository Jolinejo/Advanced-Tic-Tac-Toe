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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gamesList {
 public:
  QListWidget *listWidget;
  QPushButton *pushButton;

  void setupUi(QDialog *gamesList) {
    if (gamesList->objectName().isEmpty())
      gamesList->setObjectName("gamesList");
    gamesList->resize(400, 300);
    listWidget = new QListWidget(gamesList);
    listWidget->setObjectName("listWidget");
    listWidget->setGeometry(QRect(30, 20, 321, 231));
    pushButton = new QPushButton(gamesList);
    pushButton->setObjectName("pushButton");
    pushButton->setGeometry(QRect(120, 260, 141, 32));

    retranslateUi(gamesList);

    QMetaObject::connectSlotsByName(gamesList);
  }  // setupUi

  void retranslateUi(QDialog *gamesList) {
    gamesList->setWindowTitle(
        QCoreApplication::translate("gamesList", "Dialog", nullptr));
    pushButton->setText(
        QCoreApplication::translate("gamesList", "Reply Game", nullptr));
  }  // retranslateUi
};

namespace Ui {
class gamesList : public Ui_gamesList {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_GAMESLIST_H
