#include "startgame.h"
#include "ui_startgame.h"
#include <QMessageBox>
#include <QApplication>
#include <iostream>
#include <vector>
#include "mainwindow.h"
#include <ctime>
#include <fstream>
#include <QPushButton>

Startgame::Startgame(QWidget *parent, const QString &p1, const QString &p2)
    : QDialog(parent)
    , ui(new Ui::Startgame)
    , player1(p1)
    , player2(p2)
{
    ui->setupUi(this);

    // Initialize grid and currentPlayer
    currentPlayer = Player::X;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = Player::None;
        }
    }

    // Connect button clicks to handleButtonClick
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout_play->itemAtPosition(row, col)->widget());
            connect(button, &QPushButton::clicked, [=]() { handleButtonClick(row, col, button); });
        }
    }
}

Startgame::~Startgame()
{
    delete ui;
}

void Startgame::handleButtonClick(int row, int col, QPushButton* button)
{
    if (grid[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid[row][col] = currentPlayer;
    QString text = (currentPlayer == Player::X) ? "X" : "O";
    button->setText(text);
    button->setEnabled(false);
    gameMoves.push_back(text + QString::number(row) + QString::number(col));
    gameMoves.append(text + QString::number(row) + QString::number(col));

    if (checkWin(currentPlayer)) {
        QMessageBox::information(nullptr, "Game Over", QString("%1 wins!").arg(text));
        saveGame();
        QApplication::quit();
    } else if (checkTie()) {
        QMessageBox::information(nullptr, "Game Over", "Tie!");
        saveGame();
        QApplication::quit();
    } else {
        // Switch to the other player's turn
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }
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

#include <fstream>
#include <ctime>

void Startgame::saveGame() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::string concatenatedString = std::string(timestamp) + "*" + player1.toStdString() + "*" + player2.toStdString();
    for (const auto& move : gameMoves) {
        concatenatedString = concatenatedString + "*" + move.toStdString();
    }
    std::ofstream file(getPath("/history.txt").toStdString(), std::ios::app);
    if (file.is_open()) {
        file << concatenatedString << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}
