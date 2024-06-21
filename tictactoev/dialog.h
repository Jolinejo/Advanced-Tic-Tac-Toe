#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <string>
#include "gameslist.h"
#include "startgame.h"
using namespace std;

class MainWindow;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, int mode = 1, string p1 = "", string p2 = "");
    ~Dialog();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_display1_clicked();

    void on_pushButton_display2_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Dialog *ui;
    int gameMode;
    string player1;
    string player2;
    gamesList *games;
    Startgame * startgame;
    MainWindow *mainWindow;
};

void executeAi(string player);
#endif // DIALOG_H

