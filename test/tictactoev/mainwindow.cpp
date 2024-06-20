#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_playerxplayer_clicked()
{
    hide();
    sign = new signin(this, "1");
    sign ->show();

}


void MainWindow::on_pushButton_AI_clicked()
{
    hide();
    sign = new signin(this, "2");
    sign ->show();
}

