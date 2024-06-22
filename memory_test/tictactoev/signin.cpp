#include "signin.h"

#include <string>

#include "QMessageBox"
#include "mainwindow.h"
#include "ui_signin.h"
using namespace std;
signin::signin(QWidget *parent, string variable)
    : QDialog(parent), variable_(variable), ui(new Ui::signin) {
  ui->setupUi(this);
  ui->lineEdit_password->setEchoMode(QLineEdit::Password);
  connect(ui->checkBox_showpassword, &QCheckBox::stateChanged, this,
          &signin::on_checkBox_showpassword_stateChanged);
}

signin::~signin() {
  if (variable_ == "1")
    delete sign2_;
  else
    delete dialog_;
  if (signup_clicked_) delete signup_;
  delete ui;
}

void signin::on_pushButton_login_clicked() {
  QString username = ui->lineEdit_username->text();
  QString password = ui->lineEdit_password->text();
  if (CheckValid(username.toStdString(), password.toStdString()) == 1) {
    QMessageBox ::information(this, "login",
                              "username and password is correct");
    if (variable_ == "1") {
      hide();
      sign2_ = new signin2(this, username.toStdString());
      sign2_->show();
    } else {
      hide();
      dialog_ = new Dialog(this, 2, username.toStdString());
      dialog_->show();
    }
  } else {
    ui->label_4->setText("Username or password is invalid");
  }
}

void signin::on_pushButton_signup1_clicked() {
  signup_ = new Signup(this);
  signup_clicked_ = true;
  signup_->show();
}

void signin::on_checkBox_showpassword_stateChanged(int arg1) {
  if (arg1 == Qt::Checked) {
    ui->lineEdit_password->setEchoMode(QLineEdit::Normal);  // Show password
  } else {
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);  // Hide password
  }
}
