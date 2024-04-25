#ifndef SIGNIN2_H
#define SIGNIN2_H

#include <QDialog>
#include"dialog.h"
#include"signup.h"
#include <string>
using namespace std;

namespace Ui {
class signin2;
}

class signin2 : public QDialog
{
    Q_OBJECT

public:
    explicit signin2(QWidget *parent = nullptr, string firstplayer = "");
    ~signin2();

private slots:
    void on_pushButton_login2_clicked();

    void on_pushButton_signup2_clicked();

    void on_checkBox_showpassword_stateChanged(int arg1);

private:
    Ui::signin2 *ui;
    Dialog* dialog;
    Signup* signup;
    string firstplayer;
};

#endif // SIGNIN2_H
