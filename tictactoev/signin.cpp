#include "signin.h"
#include "ui_signin.h"
#include"QMessageBox"
#include "mainwindow.h"
#include <string>
using namespace std;
signin::signin(QWidget *parent, string variable)
    : QDialog(parent)
    , m_variable(variable)
    , ui(new Ui::signin)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    connect(ui->checkBox_showpassword, &QCheckBox::stateChanged, this, &signin::on_checkBox_showpassword_stateChanged);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_login_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if (checkValid(username.toStdString(), password.toStdString()) == 1) {
        QMessageBox ::information(this, "login", "username and password is correct");
        if (m_variable == "1") {
            hide();
            sign2 = new signin2(this, username.toStdString());
            sign2->show();
        } else {
            hide();
            dialog= new Dialog(this, 2, username.toStdString());
            dialog->show();
        }
    } else {
        ui->label_4->setText("Username or password is invalid");
    }


}


void signin::on_pushButton_signup1_clicked()
{
    signup = new Signup(this);
    signup->show();
}

void signin::on_checkBox_showpassword_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal); // Show password
    } else {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password); // Hide password
    }
}

