#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>
#include <queue>

namespace Ui {
class gameHistory;
}

class gameHistory : public QDialog {
  Q_OBJECT

 public:
  explicit gameHistory(QWidget *parent = nullptr, std::string moves = "",
                       std::string player_who_won = "");
  ~gameHistory();

 private slots:
  void on_pushButton_play_clicked();

 private:
  Ui::gameHistory *ui;
  std::queue<std::string> move_queue_;
};

#endif  // GAMEHISTORY_H
