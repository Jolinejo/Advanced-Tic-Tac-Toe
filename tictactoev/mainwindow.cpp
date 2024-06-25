#include "mainwindow.h"
#include "globals.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    musicPlayer->setSource(QUrl("qrc:/sounds/Sneaky.mp3"));
    musicPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);
    musicPlayer->play();
}

MainWindow::~MainWindow() {
    delete sign_;
    delete ui;
    delete musicPlayer;
    delete audioOutput;
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
    if (player1 != nullptr)
        delete player1;
    if (player2 != nullptr)
        delete player2;
    QApplication::quit();
}
