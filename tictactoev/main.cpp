#include <QApplication>
#include <QFile>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "bcrypt.h"
#include "globals.h"
#include "mainwindow.h"

std::vector<User> users;  // Vector to store registered users
User* player1 = nullptr;
User* player2 = nullptr;

QString GetPath(QString file_path) {
  QString base_path = QApplication::applicationDirPath();
  int build_index = base_path.indexOf("/tictactoev");
  QString truncated_path = base_path.left(build_index);
  QString path = truncated_path + "/tictactoev" + file_path;
  return path;
}

void SplitAfterStar(const std::string& str, std::string (&result)[2]) {
  size_t index = str.find('*');
  if (index != std::string::npos) {
    result[0] = str.substr(0, index);
    result[1] = str.substr(index + 1);
  } else {
    result[0] = str;
    result[1] = "";
  }
}

int RegisterUser(std::string username, std::string password) {
  // Check if the username is already taken
  for (const auto& user : users) {
    if (user.GetUsername() == username) {
      return 0;  // Username already exists
    }
  }
  std::string hash = bcrypt::generateHash(password);

  // Create a new user and add to vector
  User new_user(username, hash);
  users.push_back(new_user);

  // Save users to file
  std::ofstream outfile(
      GetPath("/register.txt").toStdString());  // Use std::ofstream

  for (const auto& user : users) {
    outfile << user.GetUsername() << "*" << user.GetPassword() << std::endl;
  }

  outfile.close();
  return 1;
}

void LoadUsers() {
  std::ifstream myfile(
      GetPath("/register.txt").toStdString());  // Use std::ifstream

  if (myfile.is_open()) {
    std::string line;
    while (getline(myfile, line)) {
      std::string result[2];
      SplitAfterStar(line, result);
      User new_user(result[0], result[1]);
      users.push_back(new_user);
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file." << std::endl;
  }
}

int CheckValid(std::string username, std::string password) {
  for (const auto& user : users) {
    if (username == user.GetUsername() &&
        bcrypt::validatePassword(password, user.GetPassword())) {
      if (player1 == nullptr) {
        player1 = new User(username, password);
      } else if (username == player1->GetUsername()) {
        return 2;
      } else {
        player2 = new User(username, password);
      }
      return 1;  // Valid user
    }
  }
  return 0;  // Invalid user
}

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QFile file(":/users/Wstartpage.qss");

  if (!file.open(QFile::ReadOnly)) {
    qDebug() << "Failed to open file:" << file.errorString();
  } else {
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
  }

  LoadUsers();
  MainWindow w;
  w.resize(500, 500);
  w.show();
  return a.exec();
}
