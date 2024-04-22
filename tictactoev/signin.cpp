#include "signin.h"
#include "ui_signin.h"
#include"QMessageBox"


signin::signin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_login_clicked()
{

        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        if (username == "vivianne" && password == "emad") {
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
    hide();
    signup = new Signup(this);
    signup->show();
}

