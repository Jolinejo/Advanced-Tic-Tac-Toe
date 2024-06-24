#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <string>

#include "gameslist.h"
#include "startgame.h"

class MainWindow;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog(QWidget *parent = nullptr, int mode = 1, std::string p1 = "",
                  std::string p2 = "");
  ~Dialog();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_display1_clicked();

  void on_pushButton_display2_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::Dialog *ui;
  int game_mode_;
  std::string player_1_;
  std::string player_2_;
  gamesList *games_;
  Startgame *startgame_;
  MainWindow *main_window_;
  bool start_clicked_ = false;
  bool history_clicked_ = false;
  bool sign_out_clicked_ = false;

protected:
  void closeEvent(QCloseEvent *event) override;
};

#endif  // DIALOG_H
