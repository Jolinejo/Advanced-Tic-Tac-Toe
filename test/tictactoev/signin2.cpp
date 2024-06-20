#include "signin2.h"
#include "ui_signin2.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "usermanager.h" // Include the UserManager header

signin2::signin2(QWidget *parent, std::string name)
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

    // Instantiate UserManager
    UserManager userManager;

    // Check if user is valid
    int result = userManager.checkValid(username2.toStdString(), password2.toStdString());
    if (result == 1) {
        QMessageBox::information(this, "Login", "Username and password are correct");
        hide();
        dialog = new Dialog(this, 1, firstplayer, username2.toStdString());
        dialog->show();
    } else if (result == 0) {
        ui->label_ifthere->setText("Username or password is invalid");
    } else {
        ui->label_ifthere->setText("User already logged in");
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
