
#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QFile>

using namespace std;

vector<User> users; // Vector to store registered users

User *player1 = nullptr;
User *player2 = nullptr;

QString getPath(QString filePath) {
    QString basePath = QApplication::applicationDirPath();
    int buildIndex = basePath.indexOf("/tictactoev");
    QString truncatedPath = basePath.left(buildIndex);
    QString path = truncatedPath + "/tictactoev" + filePath;
    return path;
}

void split_after_star(const string& s, string (&result)[2]) {
    size_t index = s.find('*');
    if (index != string::npos) {
        result[0] = s.substr(0, index);
        result[1] = s.substr(index + 1);
    } else {
        result[0] = s;
        result[1] = "";
    }
}

int registerUser(const string username, const string password) {
    // Check if the username is already taken
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            return 0; // Username already exists
        }
    }

    // Create a new user and add to vector
    User newUser(username, password);
    users.push_back(newUser);

    // Save users to file
    ofstream outfile(getPath("/register.txt").toStdString(), ios::out);

    for (const auto& user : users) {
        outfile << user.getUsername() << "*" << user.getPassword() << endl;
    }

    outfile.close();
    return 1;
}

void loadUsers() {
    ifstream myfile;
    myfile.open(getPath("/register.txt").toStdString(), ios::in);

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            string result[2];
            split_after_star(line, result);
            User newUser(result[0], result[1]);
            users.push_back(newUser);
        }
        myfile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

int checkValid(const string username, const string password) {
    for (const auto& user : users) {
        if (username == user.getUsername() && password == user.getPassword()) {
            if (player1 == nullptr)
                player1 = new User(username, password);
            else if (username == player1->getUsername())
                return 2;
            else
                player2 = new User(username, password);
            return 1; // Valid user
        }
    }
    return 0; // Invalid user
}

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

// Main function to run the tests
int main(int argc, char **argv) {
    // Initialize QApplication
    QApplication app(argc, argv);

    // Run the tests
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
