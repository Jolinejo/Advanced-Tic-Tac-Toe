#include "startgame.h"
#include "mainwindow.h"
#include "ui_startgame.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <fstream>
#include <ctime>
#include <iostream>
#include<QMediaPlayer>
#include <QAudioOutput>





using namespace std;
string winner;

QString getPath2(const QString& filePath) {
    QString basePath = QApplication::applicationDirPath();
    int buildIndex = basePath.indexOf("/tictactoev");
    QString truncatedPath = basePath.left(buildIndex);
    QString path = truncatedPath + "/tictactoev" + filePath;
    return path;
}

Startgame::Startgame(QWidget *parent, string p1, string p2, int mode)
    : QDialog(parent),
    ui(new Ui::Startgame),
    player1(p1),
    player2(p2),
    gameMode(mode)
{
    ui->setupUi(this);
    music = new QMediaPlayer();
    audio = new QAudioOutput();


    ui->label_round->setText("Round " + QString::number(currentRound));
    if (mode == 2) {
        ui->label_p2->setText("AI"); // Hide the whole button
        player2 = "AI";
    } else {
        ui->label_p2->setText(QString::fromStdString(player2) + " is O");
    }
    ui->label_p1->setText(QString::fromStdString(player1) + " is X");

    // Initialize grid and currentPlayer
    currentPlayer = Player::X;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = Player::None;
        }
    }

    // Connect button clicks to appropriate handlers based on game mode
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout_play->itemAtPosition(row, col)->widget());
            if (mode == 1) {
                connect(button, &QPushButton::clicked, [=]() { handleButtonClick(row, col, button); });
            } else if (mode == 2) {
                connect(button, &QPushButton::clicked, [=]() { handleButtonClick2(row, col, button); });
            }
        }
    }
}

Startgame::~Startgame()
{
    delete ui;
}

void Startgame::handleButtonClick(int row, int col, QPushButton *button)
{
    // Handle player's move
    if (grid[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid[row][col] = currentPlayer;
    QString text = (currentPlayer == Player::X) ? "X" : "O";
    button->setText(text);
    button->setEnabled(false);
    if(save){
        gameMoves.push_back(text + QString::number(row) + QString::number(col));}

    if (checkWin(currentPlayer)) {

        if(currentPlayer==Player::X){
            counter1 = counter1 + 1;
            winner = player1;
            ui->lcdNumber_p1->display(QString::number(counter1));
        } else {
            counter2 = counter2 + 1;
            winner = player2;
            ui->lcdNumber_p2->display(QString::number(counter2));
        }
        if (save) saveGame();
        startNextRound(); // Start the next round
    } else if (checkTie()) {
        winner = "tie";
        if (save) saveGame();
        startNextRound();
    } else {
        // Switch to the other player's turn
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }
}

void Startgame::startNextRound()
{
    ++currentRound;
    if (currentRound > MAX_ROUNDS) {
        if (counter1 > counter2) {


            // Inside your function or constructor where you want to play the media
            music->setSource(QUrl("qrc:/sounds/forx.mp3"));
            music->setAudioOutput(audio);
            audio->setVolume(0.5);
            music->play();
            QMessageBox::information(nullptr, "Game Over", QString("%1 wins!").arg(QString::fromStdString(player1)));
            QApplication::quit();
        } else if (counter2 > counter1) {
            music->setSource(QUrl("qrc:/sounds/foro.mp3"));
            music->setAudioOutput(audio);
            audio->setVolume(0.5);
            music->play();
            QMessageBox::information(nullptr, "Game Over", QString("%1 wins!").arg(QString::fromStdString(player2)));
            QApplication::quit();
        } else {
            QMessageBox::information(nullptr, "Game Over", QString("It's a tie!"));
            QApplication::quit();
        }
    }
    ui->label_round->setText("Round " + QString::number(currentRound));
    currentPlayer = Player::X;
    // Clear the grid and gameMoves vectors
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = Player::None;
        }
    }
    gameMoves.clear();

    // Clear the button texts and enable them
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout_play->itemAtPosition(row, col)->widget());
            button->setText("");
            button->setEnabled(true);
        }
    }
}



void Startgame::handleButtonClick2(int row, int col, QPushButton *button)
{
    // Handle player's move
    if (grid[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid[row][col] = currentPlayer;
    QString text = (currentPlayer == Player::X) ? "X" : "O";
    button->setText(text);
    button->setEnabled(false);
    gameMoves.push_back(text + QString::number(row) + QString::number(col));

    if (checkWin(currentPlayer)) {

        if(currentPlayer==Player::X){
            counter1 = counter1 + 1;
            winner = player1;
            ui->lcdNumber_p1->display(QString::number(counter1));
        } else {
            counter2 = counter2 + 1;
            winner = player2;
            ui->lcdNumber_p2->display(QString::number(counter2));
        }

        if(save) saveGame();
        startNextRound(); // Start the next round
    } else if (checkTie()) {
        winner = "tie";
        if(save) saveGame();
        startNextRound();
    } else {
        // Switch to the other player's turn
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;


        // AI's move
        pair<int, int> aiMoveCoords = aiMove();
        grid[aiMoveCoords.first][aiMoveCoords.second] = currentPlayer;
        QPushButton *aiButton = qobject_cast<QPushButton *>(ui->gridLayout_play->itemAtPosition(aiMoveCoords.first, aiMoveCoords.second)->widget());

        aiButton->setText((currentPlayer == Player::X) ? "X" : "O");
        aiButton->setEnabled(false);
        if(save) gameMoves.push_back(aiButton->text() + QString::number(aiMoveCoords.first) + QString::number(aiMoveCoords.second));

        if (checkWin(currentPlayer)) {

            if(currentPlayer==Player::X){
                counter1 = counter1 + 1;
                winner = player1;
                ui->lcdNumber_p1->display(QString::number(counter1));
            } else {
                counter2 = counter2 + 1;
                winner = player2;
                ui->lcdNumber_p2->display(QString::number(counter2));
            }
            if(save) saveGame();
            startNextRound(); // Start the next round
        } else if (checkTie()) {
            winner = "tie";
            if(save) saveGame();
            startNextRound();
        } else {
            // Switch to the other player's turn
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
        }
    }
}

pair<int, int> Startgame::aiMove() {
    int bestScore = INT_MIN;
    pair<int, int> bestMove = make_pair(-1, -1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == Player::None) {
                grid[i][j] = currentPlayer;  // Assume AI is always 'O' for minimization in this example
                int score = minimax(0, false);
                grid[i][j] = Player::None;
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = make_pair(i, j);
                }
            }
        }
    }
    return bestMove;
}

bool Startgame::checkWin(Player player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        // Check columns
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
        return true;

    return false;
}

bool Startgame::checkTie()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == Player::None)
                return false;
    }
    return true;
}

int Startgame::minimax(int depth, bool isMaximizingPlayer) {
    int score = evaluateBoard();

    if (score != 0) return score;
    if (checkTie()) return 0;

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == Player::None) {
                    grid[i][j] = Player::O;
                    bestScore = max(bestScore, minimax(depth + 1, false));
                    grid[i][j] = Player::None;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == Player::None) {
                    grid[i][j] = Player::X;
                    bestScore = min(bestScore, minimax(depth + 1, true));
                    grid[i][j] = Player::None;
                }
            }
        }
        return bestScore;
    }
}

int Startgame::evaluateBoard()
{
    if (checkWin(Player::O)) {
        return 10; // PLAYER_X wins
    } else if (checkWin(Player::X)) {
        return -10; // PLAYER_O wins
    } else {
        return 0; // Game not over
    }
}

void Startgame::saveGame() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::string concatenatedString = std::string(timestamp) + "*" + player1 + "*" + player2 + "*" + winner;
    for (const auto& move : gameMoves) {
        concatenatedString = concatenatedString + "*" + move.toStdString();
    }
    std::ofstream file(getPath2("/history.txt").toStdString(), std::ios::app);
    if (file.is_open()) {
        file << concatenatedString << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

void Startgame::on_checkBox_stateChanged(int arg1)
{
    save=true;
}


