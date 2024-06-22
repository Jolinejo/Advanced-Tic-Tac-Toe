#ifndef GAMESLIST_H
#define GAMESLIST_H
#include <QDialog>
#include <string>

#include "gamehistory.h"

namespace Ui {
class gamesList;
}

class gamesList : public QDialog {
  Q_OBJECT

 public:
  explicit gamesList(QWidget *parent = nullptr, std::string player = "");
  ~gamesList();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::gamesList *ui;
  std::string player_;
  gameHistory *gamehis_;
};

#endif  // GAMESLIST_H
