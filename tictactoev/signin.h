#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <string>

#include "dialog.h"
#include "signin2.h"
#include "signup.h"

using namespace std;

namespace Ui {
class signin;
}

class signin : public QDialog {
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr, std::string variable = "");
    ~signin();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signup1_clicked();
    void on_checkBox_showpassword_stateChanged(int arg1);

private:
    std::string variable_;
    Ui::signin *ui;
    signin2 *sign2_;
    Signup *signup_;
    Dialog *dialog_;
    bool signup_clicked_ = false;
};

#endif  // SIGNIN_H
