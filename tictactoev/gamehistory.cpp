#include "gamehistory.h"
#include "ui_gamehistory.h"
#include <QGridLayout>
#include <QLabel>
#include <iostream>
#include <thread>
#include <chrono>
#include <QTimer>

#include <string>

bool isValidString(const string& inputString) //make sure string is valid
{

    for (char c : inputString) {
        if (!(c == 'X' || c == 'O' || (c >= '0' && c <= '9') || c == '*')) {
            return false; // If any character is not valid, return false
        }
    }
    return true;
}


queue<string> splitAndEnqueue(string& str) {
    // Create a queue to store the parts
    queue<string> partsQueue;

    // Initialize position variable for finding '*'
    size_t pos = 0;

    // Find '*' position and split the string
    while ((pos = str.find('*', pos)) != string::npos) {
        // Push the substring from the beginning to '*'
        partsQueue.push(str.substr(0, pos));
        // Erase the part including '*'
        str.erase(0, pos + 1);
    }

    // Push the remaining part (or the only part if no '*')
    if (!str.empty()) {
        partsQueue.push(str);
    }

    return partsQueue;
}



gameHistory::gameHistory(QWidget *parent, string moves) :
    QDialog(parent),
    ui(new Ui::gameHistory)
{
    ui->setupUi(this);
    moveQueue = splitAndEnqueue(moves);
}

gameHistory::~gameHistory()
{
    delete ui;
}

int moveIndex = 0; // Index of the next move to be displayed

// Slot function for handling button click
void gameHistory::on_pushButton_play_clicked()
{
    if (!moveQueue.empty()) {
        string move = moveQueue.front();
        moveQueue.pop();

        QChar player = move[0];
        int row = move[1] - '0';
        int col = move[2] - '0';

        QString labelName = QString("label_%1").arg(row * 3 + col + 1);
        QLabel* label = ui->gridOfMoves->findChild<QLabel*>(labelName);

        if (label) {
            label->setText(player);
            qDebug() << "Label updated: " << labelName;
        } else {
            qDebug() << "Label not found: " << labelName;
        }

        if (moveQueue.empty()) {
            ui->pushButton_play->setEnabled(false);
        }
    } else {
        ui->pushButton_play->setEnabled(false);
    }

    // Force a UI refresh
    QApplication::processEvents();
}







