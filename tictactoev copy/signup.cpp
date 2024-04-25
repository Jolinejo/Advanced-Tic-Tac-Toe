#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>
Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pushButton_sign_clicked()
{

    QString username = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    if (registerUser(username.toStdString(), password.toStdString())) {
        QMessageBox::information(this, "Registration", "User registered successfully");
        hide();
    } else {
        QMessageBox::warning(this, "Registration", "User already exists");
    }

}

