#include "signin.h"
#include "ui_signin.h"
#include"QMessageBox"
#include "mainwindow.h"

signin::signin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signin)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_login_clicked()
{

        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        if (checkValid(username.toStdString(), password.toStdString())) {
            QMessageBox ::information(this, "login", "username and password is correct");
            hide();
            sign2 = new signin2(this);
            sign2->show();
        } else {
            QMessageBox ::warning(this, "login", "username or password is invalid");
        }


}


void signin::on_pushButton_signup1_clicked()
{
    signup = new Signup(this);
    signup->show();
}

