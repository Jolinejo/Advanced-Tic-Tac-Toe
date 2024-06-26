#include "signin2.h"
#include "globals.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "ui_signin2.h"

signin2::signin2(QWidget *parent, string name)
    : QDialog(parent), ui(new Ui::signin2), first_player_(name) {
  ui->setupUi(this);
  ui->lineEdit_password2->setEchoMode(QLineEdit::Password);
  connect(ui->checkBox_showpassword, &QCheckBox::stateChanged, this,
          &signin2::on_checkBox_showpassword_stateChanged);
  setWindowTitle("Player2 Signin");
}

signin2::~signin2() {
    if (dialog_ != nullptr){
        delete dialog_;
        dialog_ = nullptr;
    }

    if (signup_ != nullptr) {delete signup_;
        signup_ = nullptr;}
  delete ui;
}

void signin2::on_pushButton_login2_clicked() {
  QString username2 = ui->lineEdit_username2->text();
  QString password2 = ui->lineEdit_password2->text();
  if (CheckValid(username2.toStdString(), password2.toStdString()) == 1) {
    QMessageBox ::information(this, "login",
                              "username and password is correct");
    hide();
    dialog_ = new Dialog(this, 1, first_player_, username2.toStdString());
    dialog_->show();
  } else if (CheckValid(username2.toStdString(), password2.toStdString()) ==
             0) {
    ui->label_ifthere->setText("Username or password is invalid");
  } else {
    ui->label_ifthere->setText("user already logged in");
  }
}

void signin2::on_pushButton_signup2_clicked() {
  signup_clicked_ = true;
  signup_ = new Signup(this);
  signup_->show();
}

void signin2::on_checkBox_showpassword_stateChanged(int arg1) {
  if (arg1 == Qt::Checked) {
    ui->lineEdit_password2->setEchoMode(QLineEdit::Normal);
  } else {
    ui->lineEdit_password2->setEchoMode(QLineEdit::Password);  // Hide password
  }
}
void signin2::closeEvent(QCloseEvent *event) {
  QApplication::quit();
}
