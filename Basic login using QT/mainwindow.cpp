#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    std::string myString = username.toStdString();
    QString password = ui->lineEdit_2->text();
    std::string myString2 = password.toStdString();
    std::string text = get_name(myString, myString2);
    QString qtString = QString::fromStdString(text);
    QMessageBox::information(this, "toz fek", qtString);
}

