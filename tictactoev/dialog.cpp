#include "dialog.h"
#include "ui_dialog.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <vector>
#include "mainwindow.h"
#include <ctime>
#include <fstream>


Dialog::Dialog(QWidget *parent, int mode, string p1, string p2)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , gameMode(mode)
    , player1(p1)
    , player2(p2)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


enum class Player {
    None,
    X,
    O
};

Player currentPlayer = Player::X;
Player grid[3][3] = { { Player::None, Player::None, Player::None },
                     { Player::None, Player::None, Player::None },
                     { Player::None, Player::None, Player::None } };

vector<string> gameMoves;

string firstplayer;
string secondplayer;

bool checkWin(Player player)
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

bool checkTie()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == Player::None)
                return false;
    }
    return true;
}


void saveGame(){

    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    string concatenatedString = string(timestamp) + "*" + firstplayer + "*" + secondplayer;
    for (const auto& move : gameMoves) {
        concatenatedString = concatenatedString + "*" + move;
    }
    if (ifstream(getPath("/history.txt").toStdString())) {
        ofstream file(getPath("/history.txt").toStdString(), ios::app);
        file << concatenatedString << endl;
        file.close();
    } else {
        ofstream file(getPath("/history.txt").toStdString());
        file << concatenatedString << endl;
        file.close();
    }

}

void handleButtonClick(int row, int col, QPushButton* button)
{
    if (grid[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid[row][col] = currentPlayer;
    string text = currentPlayer == Player::X ? "X" : "O";
    button->setText(QString::fromStdString(text));
    button->setEnabled(false);
    gameMoves.push_back(text + to_string(row) + to_string(col));

    if (checkWin(currentPlayer)) {
        QMessageBox::information(nullptr, "Game Over", QString("%1 wins!").arg(currentPlayer == Player::X ? "X" : "O"));
        saveGame();
        QApplication::quit();
    } else if (checkTie()) {
        QMessageBox::information(nullptr, "Game Over", QString("Tie!"));
        saveGame();
        QApplication::quit();
    } else {
        // Switch to the other player's turn
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }
}

void executeGame() {

    QWidget* window2 = new QWidget;
    QGridLayout* layout = new QGridLayout(window2);

    const int gridSize = 3;
    QPushButton* buttons[gridSize][gridSize];

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            QPushButton* button = new QPushButton(window2);
            button->setFixedSize(100, 100); // Adjust the button size as needed
            layout->addWidget(button, row, col);
            buttons[row][col] = button;

            QAbstractButton::connect(button, &QPushButton::clicked, [=]() {
                handleButtonClick(row, col, button);
            });
        }
    }

    window2->setLayout(layout);
    window2->setWindowTitle("Tic Tac Toe");
    window2->show();

}

void Dialog::on_pushButton_clicked()
{
    hide();
    firstplayer = player1;
    secondplayer = player2;
    if (gameMode == 1)
        executeGame();
    else {
        executeAi(player1);
        std::cout<<"here";
    }
}
