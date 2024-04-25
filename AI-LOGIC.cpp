#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int BOARD_SIZE = 3;
const char EMPTY_CELL = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY_CELL));

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
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

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You are Player O. Make your move by entering row and column numbers (0-indexed)." << endl;

    while (true) {
        displayBoard();

        // Player O's turn
        int row, col;
        cout << "Player O's turn. Enter row and column: ";
        cin >> row >> col;
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY_CELL) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row][col] = PLAYER_O;

        if (isWinner(PLAYER_O)) {
            displayBoard();
            cout << "Player O wins!" << endl;
            break;
        }
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        // AI's turn
        cout << "AI's turn..." << endl;
        pair<int, int> aiMoveCoords = aiMove();
        board[aiMoveCoords.first][aiMoveCoords.second] = PLAYER_X;

        if (isWinner(PLAYER_X)) {
            displayBoard();
            cout << "AI wins!" << endl;
            break;
        }
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
