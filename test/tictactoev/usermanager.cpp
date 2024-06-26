#include "usermanager.h"
#include <fstream>
#include <iostream>
#include <QApplication>

UserManager::UserManager() : player1(nullptr), player2(nullptr) {}

void UserManager::loadUsers() {
    std::ifstream myfile;
    std::string filePath = getPath("/register.txt").toStdString();

    // Check if the file exists, if not create it
    std::ofstream checkFile(filePath, std::ios::app);
    if (!checkFile.is_open()) {
        std::cout << "Unable to create file." << std::endl;
        return;
    }
    checkFile.close();
    myfile.open(filePath, std::ios::in);
    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            std::string result[2];
            split_after_star(line, result);
            User newUser(result[0], result[1]);
            users.push_back(newUser);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

int UserManager::registerUser(const std::string& username, const std::string& password) {
    // Check if the username is already taken
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            return 0; // Username already exists
        }
    }
    std::string hash = bcrypt::generateHash(password);

    // Create a new user and add to vector
    User newUser(username, hash);
    users.push_back(newUser);

    // Save users to file
    std::ofstream outfile(getPath("/register.txt").toStdString(), std::ios::out);

    for (const auto& user : users) {
        outfile << user.getUsername() << "*" << user.getPassword() << std::endl;
    }

    outfile.close();
    return 1;
}

int UserManager::checkValid(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (username == user.getUsername() && bcrypt::validatePassword(password, user.getPassword())) {
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

QString UserManager::getPath(const QString& filePath) {
    QString basePath = QApplication::applicationDirPath();
    int buildIndex = basePath.indexOf("/tictactoev");
    QString truncatedPath = basePath.left(buildIndex);
    QString path = truncatedPath + "/tictactoev" + filePath;
    return path;
}

void UserManager::split_after_star(const std::string& s, std::string (&result)[2]) {
    size_t index = s.find('*');
    if (index != std::string::npos) {
        result[0] = s.substr(0, index);
        result[1] = s.substr(index + 1);
    } else {
        result[0] = s;
        result[1] = "";
    }
}
