#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include <QString>
#include <string>
#include<QGridLayout>
#include<QtMultimedia>
#include<QAudioOutput>
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
    bool checkWin(Player player);
    bool checkTie();
    Player grid[3][3];
    pair<int, int> aiMove();
    int minimax(int depth, bool isMaximizer);
    void saveGame();
    bool save=false;
    QVector<QString> gameMoves;
    string winner;
    ~Startgame();

private slots:
    void handleButtonClick(int row, int col, QPushButton* button);
    void handleButtonClick2(int row, int col, QPushButton* button);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Startgame *ui;
    Player currentPlayer;
    string player1;
    string player2;
    int gameMode;
    int evaluateBoard();
    int counter1 = 0;
    int counter2 = 0;
    int currentRound = 1;
    static const int MAX_ROUNDS = 3;

    void startNextRound();
    QMediaPlayer * music;
    QAudioOutput *audio;
};

#endif // STARTGAME_H
