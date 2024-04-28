
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>


#include <gtest/gtest.h>
#include <QApplication>
#include <fstream>
#include "mainwindow.h" // Include your header file with User class definition

// Test fixture for your tests
class TicTacToeTest : public ::testing::Test {
protected:
    // Optional: Set up common resources for your tests
    void SetUp() override {
        // Initialize any common resources if needed
        users.clear(); // Clear users vector before each test
    }

    // Optional: Clean up after your tests
    void TearDown() override {
        // Clean up any resources if needed
    }
};

// Test case for registerUser function
TEST_F(TicTacToeTest, RegisterUser) {
    // Ensure users vector is empty initially
    ASSERT_TRUE(users.empty());

    // Register a new user
    int result = registerUser("testuser", "testpassword");

    // Check if registration was successful
    ASSERT_EQ(result, 1);

    // Check if the user was added to the vector
    ASSERT_FALSE(users.empty());
    ASSERT_EQ(users.back().getUsername(), "testuser");
    ASSERT_EQ(users.back().getPassword(), "testpassword");
}

// Test case for checkValid function
TEST_F(TicTacToeTest, CheckValid) {
    // Ensure users vector is not empty
    ASSERT_FALSE(users.empty());

    // Check a valid user
    int result = checkValid("testuser", "testpassword");

    // Check if validation was successful
    ASSERT_EQ(result, 1);

    // Check an invalid user
    result = checkValid("invaliduser", "invalidpassword");

    // Check if validation failed
    ASSERT_EQ(result, 0);
}

// Test case for loadUsers function
TEST_F(TicTacToeTest, LoadUsers) {
    // Ensure users vector is empty initially
    ASSERT_TRUE(users.empty());

    // Create a sample user file
    std::ofstream file(getPath("/register.txt").toStdString());
    file << "user1*password1\n";
    file << "user2*password2\n";
    file.close();

    // Load users from file
    loadUsers();

    // Check if users were loaded correctly
    ASSERT_EQ(users.size(), 2);
    ASSERT_EQ(users[0].getUsername(), "user1");
    ASSERT_EQ(users[0].getPassword(), "password1");
    ASSERT_EQ(users[1].getUsername(), "user2");
    ASSERT_EQ(users[1].getPassword(), "password2");
}

// Test case for registering duplicate user
TEST_F(TicTacToeTest, RegisterDuplicateUser) {
    // Register a user
    registerUser("testuser", "testpassword");

    // Try registering the same user again
    int result = registerUser("testuser", "testpassword");

    // Check if registration failed
    ASSERT_EQ(result, 0);
}

// Test case for registering with an existing username
TEST_F(TicTacToeTest, RegisterWithExistingUsername) {
    // Load users from file
    loadUsers();

    // Register a user with an existing username
    int result = registerUser("user1", "testpassword");

    // Check if registration failed
    ASSERT_EQ(result, 0);
}

// Test case for checking invalid user with no users loaded
TEST_F(TicTacToeTest, CheckInvalidWithNoUsersLoaded) {
    // Ensure users vector is empty
    ASSERT_TRUE(users.empty());

    // Check an invalid user
    int result = checkValid("testuser", "testpassword");

    // Check if validation failed
    ASSERT_EQ(result, 0);
}

// Test case for checking valid user with single player
TEST_F(TicTacToeTest, CheckValidSinglePlayer) {
    // Register a user
    registerUser("testuser", "testpassword");

    // Check a valid user
    int result = checkValid("testuser", "testpassword");

    // Check if validation was successful
    ASSERT_EQ(result, 1);
    // Check if player1 is set correctly
    ASSERT_NE(player1, nullptr);
    ASSERT_EQ(player1->getUsername(), "testuser");
    ASSERT_EQ(player1->getPassword(), "testpassword");
}

// Test case for checking valid user with two players
TEST_F(TicTacToeTest, CheckValidTwoPlayers) {
    // Register two users
    registerUser("user1", "password1");

