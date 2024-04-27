#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include <QString>

namespace Ui {
class Startgame;
}

enum class Player { None, X, O };

class Startgame : public QDialog
{
    Q_OBJECT

public:
    explicit Startgame(QWidget *parent = nullptr, const QString &p1 = "", const QString &p2 = "");
    ~Startgame();

private slots:
    void handleButtonClick(int row, int col, QPushButton* button);
    bool checkWin(Player player);
    bool checkTie();
    void saveGame();

private:
    Ui::Startgame *ui;
    Player currentPlayer;
    Player grid[3][3];
    QString player1;
    QString player2;
    QVector<QString> gameMoves;
};

#endif // STARTGAME_H
