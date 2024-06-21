#include <gtest/gtest.h>
#include <fstream>
#include "usermanager.h"
#include <vector>
#include <queue>
#include <map>

// Functions to be tested
vector<string> split(const string& s, char delimiter);
queue<vector<string>> filterNames(const string& name);

class UserManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a temporary history file for testing
        std::ofstream outFile(userManager.getPath("/history.txt").toStdString());
        outFile << "Game1*player1*player2*winner1*details1\n";
        outFile << "Game2*player3*player1*winner2*details2\n";
        outFile << "Game3*player4*player5*winner3*details3\n";
        outFile.close();
    }

    void TearDown() override {
        // Truncate the temporary test file to empty after each test
        std::ofstream outfile(userManager.getPath("/history.txt").toStdString(), std::ios::out | std::ios::trunc);
        outfile.close();
    }

    UserManager userManager;
};

// Test `split` function
TEST(SplitFunctionTest, BasicSplitting) {
    string testString = "part1*part2*part3*part4*part5*part6";
    vector<string> result = split(testString, '*');

    ASSERT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], "part1");
    EXPECT_EQ(result[1], "part2");
    EXPECT_EQ(result[2], "part3");
    EXPECT_EQ(result[3], "part4");
    EXPECT_EQ(result[4], "part5*part6");
}

// Test `filterNames` function using UserManagerTest fixture
TEST_F(UserManagerTest, FilterNamesFunctionTest) {
    queue<vector<string>> resultQueue = filterNames("player1");

    ASSERT_EQ(resultQueue.size(), 2);

    vector<string> entry1 = resultQueue.front();
    resultQueue.pop();
    EXPECT_EQ(entry1[0], "Game1");
    EXPECT_EQ(entry1[1], "player1");
    EXPECT_EQ(entry1[2], "player2");
    EXPECT_EQ(entry1[3], "winner1");
    EXPECT_EQ(entry1[4], "details1");

    vector<string> entry2 = resultQueue.front();
    resultQueue.pop();
    EXPECT_EQ(entry2[0], "Game2");
    EXPECT_EQ(entry2[1], "player3");
    EXPECT_EQ(entry2[2], "player1");
    EXPECT_EQ(entry2[3], "winner2");
    EXPECT_EQ(entry2[4], "details2");
}
