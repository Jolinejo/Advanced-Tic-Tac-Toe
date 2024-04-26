#include "gameslist.h"
#include "ui_gameslist.h"

#include <QFile>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>

// Function to split string by delimiter

QString getPath2(QString filePath) {
    QString basePath = QApplication::applicationDirPath();
    int buildIndex = basePath.indexOf("/tictactoev");
    QString truncatedPath = basePath.left(buildIndex);
    QString path = truncatedPath + "/tictactoev" + filePath;
    return path;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0, end;

    while ((end = s.find(delimiter, start)) != string::npos) {
        token = s.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
    }
    tokens.push_back(s.substr(start)); // Get the last token
    return tokens;
}

queue<vector<string>> filterNames(const string& name) {
    ifstream file;
    file.open(getPath2("/history.txt").toStdString(), ios::in);
    queue<vector<string>> resultQueue;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << endl;
        return resultQueue;
    }

    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, '*');

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
    queue<vector<string>> results = filterNames(playerName);

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
