#include <iostream>
using namespace std;

bool checkplace(char board[3][3], int col, int row) {
    return board[row][col] != ' ';
}

void play(char board[3][3], char symbol) {
    int row, col;
    cout << "Player " << symbol << ": please enter where you want to play (row col): ";
    cin >> row >> col;

    while (checkplace(board, col, row)) {
        cout << "Invalid move. Try again." << endl;
        cout << "Player " << symbol << ": please enter where you want to play (row col): ";
        cin >> row >> col;
    }

    board[row][col] = symbol;
}

bool checkwinner(char board[3][3], char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return true;

    return false;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    for (int i = 0; i < 9; ++i) {
        if (i % 2 == 0)
            play(board, 'x');
        else
            play(board, 'o');

        // Check for a winner after 5 moves
        if (i >= 4) {
            if (checkwinner(board, 'x')) {
                cout << "Player x wins!" << endl;
                break;
            } else if (checkwinner(board, 'o')) {
                cout << "Player o wins!" << endl;
                break;
            } else if (i == 8) {
                cout << "It's a tie!" << endl;
            }
        }
    }

    return 0;
}
