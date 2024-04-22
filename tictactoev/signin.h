#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include"signin2.h"
#include "signup.h"

namespace Ui {
class signin;
}

class signin : public QDialog
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup1_clicked();

private:
    Ui::signin *ui;
    signin2 * sign2;
    Signup* signup;
};

#endif // SIGNIN_H
