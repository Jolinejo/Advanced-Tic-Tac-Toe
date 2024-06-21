#include "gameslist.h"
#include "ui_gameslist.h"
#include "usermanager.h"
#include <QFile>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <map>


map<string, string> mapOfGames;
string winnerToDisplay;
// Function to split string by delimiter

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0, end;
    int count = 0; // Counter for the number of splits

    while ((end = s.find(delimiter, start)) != string::npos) {
        token = s.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
        count++; // Increment the split count

        // After collecting the first three elements, stop splitting and take the rest as one token
        if (count == 4) {
            break;
        }
    }

    // Add the remainder of the string as the last token
    tokens.push_back(s.substr(start));
    return tokens;
}

queue<vector<string>> filterNames(const string& name) {
    UserManager userManager;

    ifstream file;
    file.open(userManager.getPath("/history.txt").toStdString(), ios::in);
    queue<vector<string>> resultQueue;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << endl;
        return resultQueue;
    }
    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, '*');
        string text = parts[0] + ": " + parts[1] + " VS " + parts[2];
        winnerToDisplay = parts[3];
        mapOfGames[text] = parts[4];
        if (name == parts[1] || name == parts[2]) {
            resultQueue.push(parts);
        }
    }
    file.close();
    return resultQueue;
}

gamesList::gamesList(QWidget *parent, string playerName)
    : QDialog(parent)
    , ui(new Ui::gamesList)
    , player(playerName)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton:disabled { background-color: #87CEFA; }");
    queue<vector<string>> results = filterNames(playerName);
    if (results.empty()) {
        ui->pushButton->setText("No history available");
        ui->pushButton->setEnabled(false);
    }

    // Display the results
    while (!results.empty()) {
        vector<string> entry = results.front();
        string text = entry[0] + ": " + entry[1] + " VS " + entry[2];
        ui->listWidget->addItem(QString::fromStdString(text));
        results.pop();
    }


}

gamesList::~gamesList()
{
    delete ui;
}

void gamesList::on_pushButton_clicked()
{
    string key = ui->listWidget->currentItem()->text().toStdString();
    gamehis = new gameHistory(this, mapOfGames[key], winnerToDisplay);
    gamehis->show();
}

