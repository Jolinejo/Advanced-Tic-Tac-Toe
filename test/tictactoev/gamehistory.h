#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>
#include <queue>

using namespace std;
namespace Ui {
class gameHistory;
}

class gameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit gameHistory(QWidget *parent = nullptr, string moves = "", string playerWhoWon = "");
    ~gameHistory();

private slots:
    void on_pushButton_play_clicked();

private:
    Ui::gameHistory *ui;
    queue<string> moveQueue;
};

bool isValidString(const string& inputString);
queue<string> splitAndEnqueue(string& str);

#endif // GAMEHISTORY_H
