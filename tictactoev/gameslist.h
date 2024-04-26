#ifndef GAMESLIST_H
#define GAMESLIST_H
#include "gamehistory.h"
#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class gamesList;
}

class gamesList : public QDialog
{
    Q_OBJECT

public:
    explicit gamesList(QWidget *parent = nullptr, string player = "");
    ~gamesList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gamesList *ui;
    string player;
    gameHistory *gamehis;
};

#endif // GAMESLIST_H
