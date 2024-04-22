#ifndef SIGNIN2_H
#define SIGNIN2_H

#include <QDialog>
#include"dialog.h"
#include"signup.h"

namespace Ui {
class signin2;
}

class signin2 : public QDialog
{
    Q_OBJECT

public:
    explicit signin2(QWidget *parent = nullptr);
    ~signin2();

private slots:
    void on_pushButton_login2_clicked();

    void on_pushButton_signup2_clicked();

private:
    Ui::signin2 *ui;
    Dialog* dialog;
    Signup* signup;
};

#endif // SIGNIN2_H
