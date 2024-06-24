#include "gameslist.h"

#include <QFile>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <stdlib.h>

#include "ui_gameslist.h"

std::map<std::string, std::string> map_of_games;
std::map<std::string, std::string> winner_to_display;
// Function to split string by delimiter

QString GetPath2(QString file_path) {
  QString base_path = QApplication::applicationDirPath();
  int build_index = base_path.indexOf("/tictactoev");
  QString truncated_path = base_path.left(build_index);
  QString path = truncated_path + "/tictactoev" + file_path;
  return path;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  size_t start = 0, end;
  int count = 0;  // Counter for the number of splits

  while ((end = s.find(delimiter, start)) != std::string::npos) {
    token = s.substr(start, end - start);
    tokens.push_back(token);
    start = end + 1;
    count++;  // Increment the split count

    // After collecting the first three elements, stop splitting and take the
    // rest as one token
    if (count == 4) {
      break;
    }
  }

  // Add the remainder of the string as the last token
  tokens.push_back(s.substr(start));
  return tokens;
}

std::queue<std::vector<std::string>> FilterNames(const std::string &name, int &losses, int &wins) {
  std::ifstream file;
  file.open(GetPath2("/history.txt").toStdString(), std::ios::in);
  std::queue<std::vector<std::string>> result_queue;

  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << std::endl;
    return result_queue;
  }
  std::string line;
  while (getline(file, line)) {
    std::vector<std::string> parts = split(line, '*');
    std::string text = parts[0] + ": " + parts[1] + " VS " + parts[2];
    winner_to_display[text] = parts[3];
    map_of_games[text] = parts[4];
    if (name == parts[1] || name == parts[2]) {
      result_queue.push(parts);
      if (parts[3] == name)
        wins++;
      else if (parts[3] != "tie")
        losses++;
    }
  }
  file.close();
  return result_queue;
}

gamesList::gamesList(QWidget *parent, std::string player_name)
    : QDialog(parent), ui(new Ui::gamesList), player_(player_name) {
  ui->setupUi(this);
  ui->pushButton->setStyleSheet(
      "QPushButton:disabled { background-color: #87CEFA; }");
  int losses = 0;
  int wins = 0;
  std::queue<std::vector<std::string>> results = FilterNames(player_name, losses, wins);
  if (results.empty()) {
    ui->pushButton->setText("No history available");
    ui->label->setText("Won: 0");
    ui->label_2->setText("Lost: 0");
    ui->pushButton->setEnabled(false);
  }
  else {
    std::string text1 = "Won: " + std::to_string(wins);
    std::string text2 = "Lost: " + std::to_string(losses);
    ui->label->setText(QString::fromStdString(text1));
    ui->label_2->setText(QString::fromStdString(text2));
  }

  // Display the results
  while (!results.empty()) {
    std::vector<std::string> entry = results.front();
    std::string text = entry[0] + ": " + entry[1] + " VS " + entry[2];
    ui->listWidget->addItem(QString::fromStdString(text));
    results.pop();
  }
  setWindowTitle("History");
}

gamesList::~gamesList() { delete ui; }

void gamesList::on_pushButton_clicked() {
  if (ui->listWidget->currentItem() != nullptr){

    std::string key = ui->listWidget->currentItem()->text().toStdString();
    gamehis_ = new gameHistory(this, map_of_games[key], winner_to_display[key]);
    gamehis_->show();
    close();
  }
}
