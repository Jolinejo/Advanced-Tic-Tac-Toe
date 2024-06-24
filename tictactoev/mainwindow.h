#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dialog.h"
#include "signin.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_playerxplayer_clicked();

  void on_pushButton_AI_clicked();

 private:
  Ui::MainWindow *ui;
  signin *sign_;
  Dialog *dialog_;

protected:
  void closeEvent(QCloseEvent *event) override;
};

class User {
 private:
  string username;
  string password;

 public:
  User(const string name, const string pass) : username(name), password(pass) {}

  string GetUsername() const { return username; }

  string GetPassword() const { return password; }
};

int CheckValid(string username, string password);
int RegisterUser(string username, string password);
QString GetPath(QString filePath);
#endif  // MAINWINDOW_H
