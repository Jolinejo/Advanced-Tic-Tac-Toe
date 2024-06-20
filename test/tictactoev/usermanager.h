#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "bcrypt.h"
#include "mainwindow.h" // Include MainWindow header for User class

class UserManager {
public:
    UserManager();
    void loadUsers();
    int registerUser(const std::string& username, const std::string& password);
    int checkValid(const std::string& username, const std::string& password);
    QString getPath(const QString& filePath);
    const std::vector<User>& getUsers() const { return users; }

private:
    std::vector<User> users;
    User *player1;
    User *player2;

    void split_after_star(const std::string& s, std::string (&result)[2]);
};

#endif // USERMANAGER_H
