#include <gtest/gtest.h>
#include "usermanager.h"
#include <iostream>
#include <fstream>
#include "bcrypt.h" // Assuming you have bcrypt integration

// Fixture for UserManager tests
class UserManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        userManager.loadUsers(); // Load users before each test
    }

    void TearDown() override {
        // Truncate the temporary test file to empty after each test
        std::ofstream outfile(userManager.getPath("/register.txt").toStdString(), std::ios::out | std::ios::trunc);
    }

    UserManager userManager;
};

// Test user registration
TEST_F(UserManagerTest, RegisterUser) {
    EXPECT_EQ(userManager.registerUser("user2", "password2"), 1); // Registering new user
    EXPECT_EQ(userManager.registerUser("user2", "password4"), 0); // Username already exists
}

// Test user login validation
TEST_F(UserManagerTest, ValidateUserLogin) {

    EXPECT_EQ(userManager.registerUser("user2", "password2"), 1);

    // Valid login
    EXPECT_EQ(userManager.checkValid("user2", "password2"), 1); // Valid user

    // Invalid password
    EXPECT_EQ(userManager.checkValid("user2", "wrongpassword"), 0); // Invalid password

    // Attempt to login with same username when player1 is set
    EXPECT_EQ(userManager.checkValid("user2", "password2"), 2); // Already logged in
}

// Test loading users from file
TEST_F(UserManagerTest, LoadUsersFromFile) {
    // Create a temporary file with user data
    std::ofstream outfile(userManager.getPath("/register.txt").toStdString(), std::ios::out);
    outfile << "user1*" << bcrypt::generateHash("password1") << std::endl;
    outfile << "user2*" << bcrypt::generateHash("password2") << std::endl;
    outfile.close();

    // Load users from the test file
    userManager.loadUsers();

    // Check if users vector contains the expected number of users
    EXPECT_EQ(userManager.getUsers().size(), 2);

    // Check if loaded users match expected usernames and passwords
    EXPECT_EQ(userManager.getUsers()[0].getUsername(), "user1");
    EXPECT_TRUE(bcrypt::validatePassword("password1", userManager.getUsers()[0].getPassword()));
    EXPECT_EQ(userManager.getUsers()[1].getUsername(), "user2");
    EXPECT_TRUE(bcrypt::validatePassword("password2", userManager.getUsers()[1].getPassword()));
}
