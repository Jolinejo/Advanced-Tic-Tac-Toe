
#include <iostream>
#include <cassert>
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

// Test case for initializeBoard function
void testInitializeBoard() {
    initializeBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(board[i][j] == ' ');
        }
    }
}

// Test case for playerMove function
void testPlayerMove() {
    initializeBoard();
    playerMove('X');
    assert(board[0][0] == 'X');
    playerMove('O');
    assert(board[1][1] == 'O');
}

// Test case for checkWin function
void testCheckWin() {
    initializeBoard();
    // Test horizontal win
    board[0][0] = board[0][1] = board[0][2] = 'X';
    assert(checkWin('X') == true);
    // Test vertical win
    initializeBoard();
    board[0][0] = board[1][0] = board[2][0] = 'O';
    assert(checkWin('O') == true);
    // Test diagonal win
    initializeBoard();
    board[0][0] = board[1][1] = board[2][2] = 'X';
    assert(checkWin('X') == true);
    // Test anti-diagonal win
    initializeBoard();
    board[0][2] = board[1][1] = board[2][0] = 'O';
    assert(checkWin('O') == true);
    // Test no win
    initializeBoard();
    assert(checkWin('X') == false);
}

// Test case for checkDraw function
void testCheckDraw() {
    initializeBoard();
    assert(checkDraw() == false); // Initial state, not a draw
    // Fill the board without a winner
    board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', 'O'}
    };
    assert(checkDraw() == true); // All spaces filled, draw
}

// Test case for switchPlayer function
void testSwitchPlayer() {
    char currentPlayer = 'X';
    switchPlayer(currentPlayer);
    assert(currentPlayer == 'O');
    switchPlayer(currentPlayer);
    assert(currentPlayer == 'X');
}

int main() {
    // Run all test cases
    testInitializeBoard();
    testPlayerMove();
    testCheckWin();
    testCheckDraw();
    testSwitchPlayer();

    cout << "All test cases passed!" << endl;

    return 0;
}
