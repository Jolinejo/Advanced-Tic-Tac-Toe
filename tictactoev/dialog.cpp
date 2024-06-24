#include "dialog.h"

#include <QMessageBox>
#include <QPushButton>

#include "gameslist.h"  // Assuming gamesList is used here
#include "globals.h"
#include "mainwindow.h"
#include "startgame.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, int mode, std::string p1, std::string p2)
    : QDialog(parent),
      ui(new Ui::Dialog),
      game_mode_(mode),
      player_1_(p1),
      player_2_(p2) {
  ui->setupUi(this);
  setWindowTitle("Tic Tac Toe");
  if (mode == 2) {
    ui->pushButton_display2->hide();  // Hide the whole button
  } else {
    ui->pushButton_display2->setText(QString::fromStdString(player_2_) +
                                     "'s history");
  }
  ui->pushButton_display1->setText(QString::fromStdString(player_1_) +
                                   "'s history");
}

Dialog::~Dialog() {
  if (start_clicked_) delete startgame_;
  if (history_clicked_) delete games_;
  if (sign_out_clicked_) delete main_window_;
  delete ui;

}

void Dialog::on_pushButton_clicked() {
  Startgame *startgame_ = new Startgame(this, player_1_, player_2_, game_mode_);
  start_clicked_ = true;
  startgame_->show();
}

void Dialog::on_pushButton_display1_clicked() {
  gamesList *games_ = new gamesList(this, player_1_);
  history_clicked_ = true;
  games_->show();
}

void Dialog::on_pushButton_display2_clicked() {
  gamesList *games_ = new gamesList(this, player_2_);
  history_clicked_ = true;
  games_->show();
}

void Dialog::on_pushButton_2_clicked() {
    delete player1;
    if (player2 != nullptr)
        delete player2;
    player1 = nullptr;
    player2 = nullptr;
    sign_out_clicked_ = true;
    hide();
    main_window_ = new MainWindow(this);
    main_window_->show();
}

void Dialog::closeEvent(QCloseEvent *event) {
    if (player1  != nullptr)
        delete player1;
    if (player2 != nullptr)
        delete player2;
    QApplication::quit();
}

