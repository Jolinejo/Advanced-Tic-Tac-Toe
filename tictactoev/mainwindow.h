#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"signin.h"
using namespace  std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_playerxplayer_clicked();

    void on_pushButton_AI_clicked();

private:
    Ui::MainWindow *ui;
    signin * sign;


};

int checkValid(string username, string password);
int registerUser(string username, string password);
#endif // MAINWINDOW_H
