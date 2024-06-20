#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include"signin2.h"
#include "signup.h"
#include <string>
#include"dialog.h"

using namespace std;

namespace Ui {
class signin;
}

class signin : public QDialog
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr, string variable = "");
    ~signin();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup1_clicked();

    void on_checkBox_showpassword_stateChanged(int arg1);

private:
    string m_variable;
    Ui::signin *ui;
    signin2 * sign2;
    Signup* signup;
    Dialog* dialog;
};

#endif // SIGNIN_H
