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

Dialog::Dialog(QWidget *parent, int mode, string p1, string p2)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , gameMode(mode)
    , player1(p1)
    , player2(p2)
{
    ui->setupUi(this);
    if (mode == 2) {
        ui->pushButton_display2->hide(); // Hide the whole button
    } else {
        ui->pushButton_display2->setText(QString::fromStdString(player2) + "'s history");
    }
    ui->pushButton_display1->setText(QString::fromStdString(player1) + "'s history");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    hide();
    Startgame *startgame = new Startgame(this, player1, player2);
    startgame->show();
}

void Dialog::on_pushButton_display1_clicked()
{
    gamesList *games = new gamesList(this, player1);
    games->show();
}

void Dialog::on_pushButton_display2_clicked()
{
    gamesList *games = new gamesList(this, player2);
    games->show();
}

