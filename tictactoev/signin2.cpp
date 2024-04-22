#include "signin2.h"
#include "ui_signin2.h"
#include "QMessageBox"
#include "mainwindow.h"

signin2::signin2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signin2)
{
    ui->setupUi(this);
}

signin2::~signin2()
{
    delete ui;
}

void signin2::on_pushButton_login2_clicked()
{
    QString username2 = ui->lineEdit_username2->text();
    QString password2 = ui->lineEdit_password2->text();
    if (checkValid(username2.toStdString(), password2.toStdString())) {
        QMessageBox ::information(this, "login", "username and password is correct");
        hide();
        dialog= new Dialog(this);
        dialog->show();
    } else {
        QMessageBox ::warning(this, "login", "username or password is invalid");
    }
}


void signin2::on_pushButton_signup2_clicked()
{
    signup = new Signup(this);
    signup->show();
}

