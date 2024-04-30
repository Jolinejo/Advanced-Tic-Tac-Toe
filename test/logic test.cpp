
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class CellState {
    Empty,
    X,
    O
};

enum class GameState {
    InProgress,
    XWins,
    OWins,
    Draw
};

class TicTacToe {
private:
    int size;
    std::vector<std::vector<CellState>> board;
    GameState currentState;
    bool xTurn;

public:
    TicTacToe(int gridSize) : size(gridSize), currentState(GameState::InProgress), xTurn(true) {
        board = std::vector<std::vector<CellState>>(size, std::vector<CellState>(size, CellState::Empty));
    }

    void makeMove(int row, int col) {
        if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != CellState::Empty) {
            std::cout << "Invalid move. Try again." << std::endl;
            return;
        }

        board[row][col] = xTurn ? CellState::X : CellState::O;
        checkGameState();
        if (currentState == GameState::InProgress)
            xTurn = !xTurn;
    }

    GameState getState() const {
        return currentState;
    }

    void printBoard() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                switch (board[i][j]) {
                    case CellState::X:
                        std::cout << "X ";
                        break;
                    case CellState::O:
                        std::cout << "O ";
                        break;
                    case CellState::Empty:
                        std::cout << "_ ";
                        break;
                }
            }
            std::cout << std::endl;
        }
    }

private:
    void checkGameState() {
        // Check rows and columns
        for (int i = 0; i < size; ++i) {
            if (checkLine(0, i, 1, 0) || checkLine(i, 0, 0, 1))
                return;
        }

        // Check diagonals
        if (checkLine(0, 0, 1, 1) || checkLine(0, size - 1, 1, -1))
            return;

        // Check for draw
        if (std::all_of(board.begin(), board.end(), [](const std::vector<CellState>& row) {
                return std::all_of(row.begin(), row.end(), [](CellState cell) {
                    return cell != CellState::Empty;
                });
            })) {
            currentState = GameState::Draw;
            return;
        }

        // Game still in progress
        currentState = GameState::InProgress;
    }

    bool checkLine(int startX, int startY, int deltaX, int deltaY) {
        CellState startCell = board[startX][startY];
        if (startCell == CellState::Empty)
            return false;

        for (int i = 1; i < size; ++i) {
            int x = startX + i * deltaX;
            int y = startY + i * deltaY;
            if (board[x][y] != startCell)
                return false;
        }

        currentState = (startCell == CellState::X) ? GameState::XWins : GameState::OWins;
        return true;
    }
};

void testBasicFunctionality() {
    std::cout << "Testing Basic Functionality:" << std::endl;
    TicTacToe game(3); // 3x3 grid
    game.makeMove(0, 0);
    game.makeMove(1, 1);
    game.makeMove(0, 1);
    game.makeMove(1, 0);
    game.makeMove(0, 2); // X wins
    std::cout << "Game State: ";
    switch (game.getState()) {
        case GameState::XWins:
            std::cout << "X Wins!" << std::endl;
            break;
        case GameState::OWins:
            std::cout << "O Wins!" << std::endl;
            break;
        case GameState::Draw:
            std::cout << "Draw!" << std::endl;
            break;
        case GameState::InProgress:
            std::cout << "Game in Progress" << std::endl;
            break;
    }
    std::cout << std::endl;
}

void testBoardSizeVariations() {
    std::cout << "Testing Board Size Variations:" << std::endl;
    for (int size = 3; size <= 6; ++size) {
        std::cout << "Board Size: " << size << "x" << size << std::endl;
        TicTacToe game(size);
        game.printBoard();
        std::cout << std::endl;
    }
}

void testWinConditions() {
    std::cout << "Testing Win Conditions:" << std::endl;
    TicTacToe game(3); // 3x3 grid
    game.makeMove(0, 0);
    game.makeMove(0, 1);
    game.makeMove(1, 1);
    game.makeMove(0, 2);
    game.makeMove(2, 2); // X wins diagonally
    std::cout << "Game State: ";
    switch (game.getState()) {
        case GameState::XWins:
            std::cout << "X Wins!" << std::endl;
            break;
        case GameState::OWins:
            std::cout << "O Wins!" << std::endl;
            break;
        case GameState::Draw:
            std::cout << "Draw!" << std::endl;
            break;
        case GameState::InProgress:
            std::cout << "Game in Progress" << std::endl;
            break;
    }
    std::cout << std::endl;
}

void testSpecialRules() {
    std::cout << "Testing Special Rules:" << std::endl;
    TicTacToe game(3); // 3x3 grid
    game.makeMove(0, 0);
    game.makeMove(1, 0);
    game.makeMove(2, 2);
    game.makeMove(1, 1);
    game.makeMove(0, 2);
    game.makeMove(2, 1);
    std::cout << "Game State: ";
    switch (game.getState()) {
        case GameState::XWins:
            std::cout << "X Wins!" << std::endl;
            break;
        case GameState::OWins:
            std::cout << "O Wins!" << std::endl;
            break;
        case GameState::Draw:
            std::cout << "Draw!" << std::endl;
            break;
        case GameState::InProgress:
            std::cout << "Game in Progress" << std::endl;
            break;
    }
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testBoardSizeVariations();
    testWinConditions();
    testSpecialRules();
    return 0;
}
