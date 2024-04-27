#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include <QString>
#include <string>
#include<QGridLayout>
using namespace std;

namespace Ui {
class Startgame;
}

enum class Player { None, X, O };

class Startgame : public QDialog
{
    Q_OBJECT

public:
    explicit Startgame(QWidget *parent = nullptr, string p1 = "", string p2 = "",int mode=1);
    ~Startgame();

private slots:
    void handleButtonClick(int row, int col, QPushButton* button);
    void handleButtonClick2(int row, int col, QPushButton* button);
    bool checkWin(Player player);
    bool checkTie();
    void saveGame();

private:
    Ui::Startgame *ui;
    Player currentPlayer;
    Player grid[3][3];
    string player1;
    string player2;
    int gameMode;
    QVector<QString> gameMoves;
    pair<int, int> aiMove();
    int minimax(bool isMaximizer, int depth);
    int evaluateBoard();
    int counter1;
    int currentRound = 1;
    static const int MAX_ROUNDS = 3;

    void startNextRound();
};

#endif // STARTGAME_H
