#include "dialog.h"
#include "ui_dialog.h"
#include "ui_mainwindow.h"
#include "startgame.h"
#include "gameslist.h" // Assuming gamesList is used here
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <QPushButton>
#include "mainwindow.h"
#include "signin.h"
#include "globals.h"

Dialog::Dialog(QWidget *parent, int mode, string p1, string p2)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , gameMode(mode)
    , player01(p1)
    , player02(p2)
{
    ui->setupUi(this);
    if (mode == 2) {
        ui->pushButton_display2->hide(); // Hide the whole button
    } else {
        ui->pushButton_display2->setText(QString::fromStdString(player02) + "'s history");
    }
    ui->pushButton_display1->setText(QString::fromStdString(player01) + "'s history");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

        Startgame *startgame = new Startgame(this, player01, player02,gameMode);
        startgame->show();


}

void Dialog::on_pushButton_display1_clicked()
{
    gamesList *games = new gamesList(this, player01);
    games->show();
}

void Dialog::on_pushButton_display2_clicked()
{
    gamesList *games = new gamesList(this, player02);
    games->show();
}


void Dialog::on_pushButton_2_clicked()
{
    player1 = nullptr;
    player2 = nullptr;
    close();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

