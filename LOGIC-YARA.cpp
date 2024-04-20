
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' ')); // Global declaration of the game board

// Function prototypes
void initializeBoard();
void displayBoard();
void playerMove(char player);
bool checkWin(char player);
bool checkDraw();
void switchPlayer(char &currentPlayer);

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    initializeBoard();
    displayBoard();

    // Game loop
    do {
        playerMove(currentPlayer);
        displayBoard();

        // Check for win
        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
            break;
        }

        // Check for draw
        if (checkDraw()) {
            cout << "It's a draw!\n";
            gameOver = true;
            break;
        }

        // Switch players
        switchPlayer(currentPlayer);

    } while (!gameOver);

    cout << "Thanks for playing!\n";

    return 0;
}

// Initialize the game board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void displayBoard() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ((j < 2) ? '|' : ' ');
        }
        cout << endl;
        if (i < 2) {
            cout << "  -----\n";
        }
    }
}

// Player makes a move
void playerMove(char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row col): ";
    cin >> row >> col;

    switch (row) {
        case 1:
            switch (col) {
                case 1:
                    board[0][0] = player;
                    break;
                case 2:
                    board[0][1] = player;
                    break;
                case 3:
                    board[0][2] = player;
                    break;
                default:
                    cout << "Invalid move\n";
                    break;
            }
            break;
        case 2:
            switch (col) {
                case 1:
                    board[1][0] = player;
                    break;
                case 2:
                    board[1][1] = player;
                    break;
                case 3:
                    board[1][2] = player;
                    break;
                default:
                    cout << "Invalid move\n";
                    break;
            }
            break;
        case 3:
            switch (col) {
                case 1:
                    board[2][0] = player;
                    break;
                case 2:
                    board[2][1] = player;
                    break;
                case 3:
                    board[2][2] = player;
                    break;
                default:
                    cout << "Invalid move\n";
                    break;
            }
            break;
        default:
            cout << "Invalid move\n";
            break;
    }
}

// Check if the current player has won
bool checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // Found an empty space, game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

// Switch between players
void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
