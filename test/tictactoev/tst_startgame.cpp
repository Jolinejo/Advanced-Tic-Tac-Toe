#include <gtest/gtest.h>
#include <queue>
#include <string>
#include <limits.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <iostream>
#include <QString>
#include "usermanager.h"

#include "startgame.h"

// Mock QApplication to avoid initializing a real GUI application
class QApplicationMock {
public:
    static QString applicationDirPath() {
        return "/mock/application/dir";
    }
};

// Substitute the real QApplication with our mock for testing purposes
#define QApplication QApplicationMock

// Fixture for Startgame tests
class StartgameTest : public ::testing::Test {
protected:
    void SetUp() override {
        game = new Startgame(nullptr, "Player1", "Player2", 1);
    }

    void TearDown() override {
        delete game;
    }

    Startgame* game;
};


// Test checkWin function
TEST_F(StartgameTest, CheckWin) {
    game->grid[0][0] = Player::X;
    game->grid[0][1] = Player::X;
    game->grid[0][2] = Player::X;
    EXPECT_TRUE(game->checkWin(Player::X));
    EXPECT_FALSE(game->checkWin(Player::O));
}

// Test checkTie function
TEST_F(StartgameTest, CheckTie) {
    game->grid[0][0] = Player::X;
    game->grid[0][1] = Player::O;
    game->grid[0][2] = Player::X;
    game->grid[1][0] = Player::X;
    game->grid[1][1] = Player::O;
    game->grid[1][2] = Player::O;
    game->grid[2][0] = Player::O;
    game->grid[2][1] = Player::X;
    game->grid[2][2] = Player::O;
    EXPECT_TRUE(game->checkTie());
    game->grid[2][2] = Player::None;
    EXPECT_FALSE(game->checkTie());
}

// Test AI move
TEST_F(StartgameTest, AIMove) {
    game->grid[0][0] = Player::X;
    game->grid[0][1] = Player::O;
    game->grid[0][2] = Player::X;
    game->grid[1][0] = Player::O;
    game->grid[1][1] = Player::O;
    game->grid[1][2] = Player::X;
    game->grid[2][0] = Player::X;
    game->grid[2][1] = Player::None;
    game->grid[2][2] = Player::None;
    pair<int, int> move = game->aiMove();
    EXPECT_EQ(move.first, 2);
    EXPECT_EQ(move.second, 1);
}

// Test minimax algorithm
TEST_F(StartgameTest, Minimax) {
    game->grid[0][0] = Player::X;
    game->grid[0][1] = Player::O;
    game->grid[0][2] = Player::X;
    game->grid[1][0] = Player::O;
    game->grid[1][1] = Player::O;
    game->grid[1][2] = Player::X;
    game->grid[2][0] = Player::X;
    game->grid[2][1] = Player::None;
    game->grid[2][2] = Player::None;
    int score = game->minimax(0, true);
    EXPECT_EQ(score, 10);
}


// Test saveGame function
TEST_F(StartgameTest, SaveGame) {
    // Simulate some game moves and set winner
    UserManager userManager;
    game->gameMoves = {"X00", "O11", "X01", "O02", "X02"};
    game->winner = "Player1";
    game->save = true; // Make sure save is enabled

    // Call saveGame to save the game state to the file
    game->saveGame();

    // Read the file and check its contents
    std::ifstream file(userManager.getPath("/history.txt").toStdString());
    ASSERT_TRUE(file.is_open()) << "Unable to open history file for reading";

    std::string line;
    std::getline(file, line);
    file.close();

    // Check if the line contains expected data
    EXPECT_NE(line.find("Player1"), std::string::npos);
    EXPECT_NE(line.find("Player2"), std::string::npos);
    EXPECT_NE(line.find("Player1"), std::string::npos); // winner
    EXPECT_NE(line.find("X00"), std::string::npos);
    EXPECT_NE(line.find("O11"), std::string::npos);
    EXPECT_NE(line.find("X01"), std::string::npos);
    EXPECT_NE(line.find("O02"), std::string::npos);
    EXPECT_NE(line.find("X02"), std::string::npos);
}
