#include "gamehistory.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "ui_gamehistory.h"

bool IsValidString(const std::string &inputString)  // make sure string is valid
{
  for (char c : inputString) {
    if (!(c == 'X' || c == 'O' || (c >= '0' && c <= '9') || c == '*')) {
      return false;  // If any character is not valid, return false
    }
  }
  return true;
}

std::queue<std::string> SplitAndEnqueue(std::string &str) {
  // Create a queue to store the parts
  std::queue<std::string> parts_queue;

  // Initialize position variable for finding '*'
  size_t pos = 0;

  // Find '*' position and split the string
  while ((pos = str.find('*', pos)) != std::string::npos) {
    // Push the substring from the beginning to '*'
    parts_queue.push(str.substr(0, pos));
    // Erase the part including '*'
    str.erase(0, pos + 1);
  }

  // Push the remaining part (or the only part if no '*')
  if (!str.empty()) {
    parts_queue.push(str);
  }

  return parts_queue;
}

gameHistory::gameHistory(QWidget *parent, std::string moves, std::string player)
    : QDialog(parent), ui(new Ui::gameHistory) {
  ui->setupUi(this);
  move_queue_ = SplitAndEnqueue(moves);
  ui->pushButton_play->setStyleSheet(
      "QPushButton:disabled { background-color: #87CEFA; }");
  std::string labelText;
  if (player != "tie")
    labelText = "The winner is " + player;
  else
    labelText = "It's a tie!";
  ui->label_of_winner->setText(QString::fromStdString(labelText));
  setWindowTitle("Replay");
}

gameHistory::~gameHistory() { delete ui; }

int moveIndex = 0;  // Index of the next move to be displayed

// Slot function for handling button click
void gameHistory::on_pushButton_play_clicked() {
  if (!move_queue_.empty()) {
    std::string move = move_queue_.front();
    move_queue_.pop();

    QChar player = move[0];
    int row = move[1] - '0';
    int col = move[2] - '0';

    QLayoutItem *layoutItem = ui->gridOfMoves->itemAtPosition(row, col);
    QLabel *label = qobject_cast<QLabel *>(layoutItem->widget());
    if (label) {
      label->setText(player);
      label->setAlignment(Qt::AlignCenter);
    }

    if (move_queue_.empty()) {
      ui->pushButton_play->setEnabled(false);
    }
  } else {
    ui->pushButton_play->setEnabled(false);
  }

  // Force a UI refresh
  QApplication::processEvents();
}
