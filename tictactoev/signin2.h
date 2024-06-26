#ifndef SIGNIN2_H
#define SIGNIN2_H

#include <QDialog>
#include <string>

#include "dialog.h"
#include "signup.h"
using namespace std;

namespace Ui {
class signin2;
}

class signin2 : public QDialog {
  Q_OBJECT

 public:
  explicit signin2(QWidget *parent = nullptr, string firstـplayer = "");
  ~signin2();

 private slots:
  void on_pushButton_login2_clicked();
  void on_pushButton_signup2_clicked();
  void on_checkBox_showpassword_stateChanged(int arg1);

 private:
  Ui::signin2 *ui;
  Dialog *dialog_;
  Signup *signup_;
  string first_player_;
  bool signup_clicked_ = false;

 protected:
  void closeEvent(QCloseEvent *event) override;
};

#endif  // SIGNIN2_H
