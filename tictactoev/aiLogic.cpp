#include <iostream>


#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <vector>
#include <climits>

using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY_CELL = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';


vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY_CELL));

// Function to display the Tic-Tac-Toe board
void displayBoard(QGridLayout *layout, QPushButton* buttons[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            buttons[i][j]->setText(QString(board[i][j]));
            buttons[i][j]->setEnabled(board[i][j] == EMPTY_CELL);
        }
    }
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL)
                return false;
        }
    }
    return true;
}

// Function to check if a player has won
bool isWinner(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to evaluate the current board state
int evaluateBoard() {
    if (isWinner(PLAYER_X)) return 10;
    if (isWinner(PLAYER_O)) return -10;
    return 0; // Draw
}

// Minimax function
int minimax(bool isMaximizer) {
    int score = evaluateBoard();

    // Base cases
    if (score == 10) return score; // If PLAYER_X wins
    if (score == -10) return score; // If PLAYER_O wins
    if (isBoardFull()) return 0; // If it's a draw

    // If it's the maximizer's turn
    if (isMaximizer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = PLAYER_X;
                    bestScore = max(bestScore, minimax(false));
                    board[i][j] = EMPTY_CELL;
                }
            }
        }
        return bestScore;
    }
    // If it's the minimizer's turn
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = PLAYER_O;
                    bestScore = min(bestScore, minimax(true));
                    board[i][j] = EMPTY_CELL;
                }
            }
        }
        return bestScore;
    }
}

// Function to make AI move using Minimax
pair<int, int> aiMove() {
    int bestScore = INT_MIN;
    pair<int, int> move;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = PLAYER_X;
                int score = minimax(false);
                board[i][j] = EMPTY_CELL;
                if (score > bestScore) {
                    bestScore = score;
                    move = make_pair(i, j);
                }
            }
        }
    }
    return move;
}

// Function to handle button clicks
void handleButtonClick(int row, int col, QPushButton* button, QGridLayout *layout) {
    if (board[row][col] != EMPTY_CELL) {
        // The button has already been clicked, ignore it
        return;
    }

    board[row][col] = PLAYER_O;
    button->setText(QString(PLAYER_O));
    button->setEnabled(false);

    if (isWinner(PLAYER_O)) {
        QMessageBox::information(nullptr, "Game Over", "Player O wins!");
        QApplication::quit();
    } else if (isBoardFull()) {
        QMessageBox::information(nullptr, "Game Over", "It's a draw!");
        QApplication::quit();
    } else {
        // AI's turn
        pair<int, int> aiMoveCoords = aiMove();
        board[aiMoveCoords.first][aiMoveCoords.second] = PLAYER_X;
        // Find the corresponding button
        QPushButton* aiButton = dynamic_cast<QPushButton*>(layout->itemAtPosition(aiMoveCoords.first, aiMoveCoords.second)->widget());
        aiButton->setText(QString(PLAYER_X));
        aiButton->setEnabled(false);

        if (isWinner(PLAYER_X)) {
            QMessageBox::information(nullptr, "Game Over", "Player X wins!");
            QApplication::quit();
        } else if (isBoardFull()) {
            QMessageBox::information(nullptr, "Game Over", "It's a draw!");
            QApplication::quit();
        }
    }
}



void executeAi() {
    QWidget* window2 = new QWidget;
    QGridLayout* layout = new QGridLayout(window2);

    QPushButton* buttons[BOARD_SIZE][BOARD_SIZE];
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            QPushButton* button = new QPushButton; // Remove parent argument
            button->setFixedSize(100, 100);
            layout->addWidget(button, row, col);
            buttons[row][col] = button;

            // Capture row and col by value in lambda
            QObject::connect(button, &QPushButton::clicked, [row, col, button, layout]() {
                handleButtonClick(row, col, button, layout);
            });
        }
    }

    window2->setLayout(layout);
    window2->setWindowTitle("Tic Tac Toe");
    window2->show();
}
