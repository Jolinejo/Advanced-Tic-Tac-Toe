#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QFile>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(const string name, const string pass) : username(name), password(pass) {}

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }
};

vector<User> users; // Vector to store registered users

QString getPath(QString filePath) {
    QString basePath = QApplication::applicationDirPath();
    int buildIndex = basePath.indexOf("/debug");
    if (buildIndex == -1)
        buildIndex = basePath.indexOf("/build");
    QString truncatedPath = basePath.left(buildIndex);
    QString path = truncatedPath + filePath;
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
            return 1; // Valid user
        }
    }
    return 0; // Invalid user
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(getPath("/Wstartpage.qss"));

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Failed to open file:" << file.errorString();
    } else {
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }

    loadUsers();
    MainWindow w;
    w.show();
    return a.exec();
}
