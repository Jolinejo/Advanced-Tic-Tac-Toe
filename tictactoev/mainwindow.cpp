#include "mainwindow.h"

#include <QCoreApplication>

#include "globals.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  sign_ = nullptr;
  if (musicPlayer == nullptr) musicPlayer = new QMediaPlayer;
  if (audioOutput == nullptr) audioOutput = new QAudioOutput;
  musicPlayer->setSource(QUrl("qrc:/sounds/Sneaky.mp3"));
  musicPlayer->setAudioOutput(audioOutput);
  audioOutput->setVolume(0.5);
  musicPlayer->play();
}

MainWindow::~MainWindow() {
  delete sign_;
  delete ui;
  if (musicPlayer != nullptr) {
    musicPlayer->stop();
    delete musicPlayer;
    musicPlayer = nullptr;
  }
  if (audioOutput != nullptr) {
    delete audioOutput;
    audioOutput = nullptr;
  }
}

void MainWindow::on_pushButton_playerxplayer_clicked() {
  hide();
  sign_ = new signin(this, "1");
  sign_->show();
}

void MainWindow::on_pushButton_AI_clicked() {
  hide();
  sign_ = new signin(this, "2");
  sign_->show();
}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (player1 != nullptr) {
    delete player1;
    player1 = nullptr;
  }
  if (player2 != nullptr) {
    delete player2;
    player2 = nullptr;
  }
  QApplication::quit();
}

void MainWindow::on_checkBox_stateChanged(int arg1) {
  if (arg1 == Qt::Checked) {
    audioOutput->setVolume(0);  // Mute
  } else {
    audioOutput->setVolume(0.5);
  }
}
