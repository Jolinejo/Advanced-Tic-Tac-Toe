#include "signin2.h"
#include "ui_signin2.h"
#include "QMessageBox"
#include "mainwindow.h"

signin2::signin2(QWidget *parent, string name)
    : QDialog(parent)
    , ui(new Ui::signin2)
    , firstplayer(name)
{
    ui->setupUi(this);
    ui->lineEdit_password2->setEchoMode(QLineEdit::Password);
     connect(ui->checkBox_showpassword, &QCheckBox::stateChanged, this, &signin2::on_checkBox_showpassword_stateChanged);
}

signin2::~signin2()
{
    delete ui;
}

void signin2::on_pushButton_login2_clicked()
{
    QString username2 = ui->lineEdit_username2->text();
    QString password2 = ui->lineEdit_password2->text();
    if (checkValid(username2.toStdString(), password2.toStdString()) == 1) {
        QMessageBox ::information(this, "login", "username and password is correct");
        hide ();
        dialog= new Dialog(this, 1, firstplayer, username2.toStdString());
        dialog->show();
    } else if (checkValid(username2.toStdString(), password2.toStdString()) == 0) {
        QMessageBox ::warning(this, "login", "username or password is invalid");
    } else {
        QMessageBox ::warning(this, "login", "user already logged in");
    }
}


void signin2::on_pushButton_signup2_clicked()
{
    signup = new Signup(this);
    signup->show();
}


void signin2::on_checkBox_showpassword_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        ui->lineEdit_password2->setEchoMode(QLineEdit::Normal); // Show password
    } else {
        ui->lineEdit_password2->setEchoMode(QLineEdit::Password); // Hide password
    }
}

