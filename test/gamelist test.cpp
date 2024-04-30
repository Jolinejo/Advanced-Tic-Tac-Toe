
#include <QtTest>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QMessageBox>
#include <map>
#include "gameslist.h"

// Test split function
void testSplit() {
    QString testString = "Player1*Player2*X00*O11*X22";
    vector<string> expected = {"Player1", "Player2", "X00*O11*X22"};
    QCOMPARE(split(testString.toStdString(), '*'), expected);
}

// Test filterNames function
void testFilterNames() {
    // Create a test history file
    QFile file(getPath2("/test_history.txt"));
    QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Text));
    QTextStream out(&file);
    out << "Player1*Player2*X00*O11*X22\n";
    out << "Player2*Player3*O02*X11*O20\n";
    out << "Player1*Player3*X01*O11*X21\n";
    file.close();

    queue<vector<string>> results = filterNames("Player1");
    QCOMPARE(results.size(), 2);

    QFile::remove(getPath2("/test_history.txt"));
}

// Test gamesList constructor
void testGamesListConstructor() {
    gamesList list(nullptr, "Player1");
    QVERIFY(list.ui->listWidget->count() == 2);
}

// Test gamesList button click slot
void testGamesListButtonClick() {
    gamesList list(nullptr, "Player1");
    list.ui->listWidget->setCurrentRow(0);

    QSignalSpy spy(list.ui->pushButton, &QPushButton::clicked);
    QVERIFY(spy.isValid());

    list.on_pushButton_clicked();
    QVERIFY(list.gamehis != nullptr);
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QApplication app(argc, argv);

    // Run the tests
    testSplit();
    testFilterNames();
    testGamesListConstructor();
    testGamesListButtonClick();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
