#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
bool checkplace(char board[3][3], int col, int row);
void play(char board[3][3], char symbol);
bool checkwinner(char board[3][3], char symbol);

// Test case for checkplace function
void testCheckplace() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    // Test case 1: Valid empty space
    assert(checkplace(board, 0, 0) == false);

    // Test case 2: Occupied space
    board[1][1] = 'x';
    assert(checkplace(board, 1, 1) == true);
}

// Test case for play function
void testPlay() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    // Test case 1: Valid move
    play(board, 'x');
    assert(board[0][0] == 'x');

    // Test case 2: Invalid move
    board[1][1] = 'o';
    play(board, 'x');
    assert(board[1][1] == 'o');
}

// Test case for checkwinner function
void testCheckwinner() {
    char board1[3][3] = { {'x', 'x', 'x'}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char board2[3][3] = { {'o', ' ', ' '}, {'o', ' ', ' '}, {'o', ' ', ' '} };
    char board3[3][3] = { {'x', ' ', ' '}, {' ', 'x', ' '}, {' ', ' ', 'x'} };
    char board4[3][3] = { {'x', 'o', 'x'}, {'x', 'x', 'o'}, {'o', 'x', 'o'} };

    // Test case 1: Player X wins in a row
    assert(checkwinner(board1, 'x') == true);

    // Test case 2: Player O wins in a column
    assert(checkwinner(board2, 'o') == true);

    // Test case 3: Player X wins diagonally
    assert(checkwinner(board3, 'x') == true);

    // Test case 4: No winner, tie game
    assert(checkwinner(board4, 'x') == false);
    assert(checkwinner(board4, 'o') == false);
}

// Function to check if the place on the board is empty
bool checkplace(char board[3][3], int col, int row) {
    return board[row][col] != ' ';
}

// Function to play a move on the board
void play(char board[3][3], char symbol) {
    int row, col;
    cout << "Player " << symbol << ": please enter where you want to play (row col): ";
    cin >> row >> col;

    while (row < 0 || row >= 3 || col < 0 || col >= 3 || checkplace(board, col, row)) {
        cout << "Invalid move. Try again." << endl;
        cout << "Player " << symbol << ": please enter where you want to play (row col): ";
        cin >> row >> col;
    }

    board[row][col] = symbol;
}

// Function to check if a player has won the game
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
    // Run all test cases
    testCheckplace();
    testPlay();
    testCheckwinner();

    cout << "All test cases passed!" << endl;

    return 0;
}
