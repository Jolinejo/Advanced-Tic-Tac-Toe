
#include <QtTest>
#include <QSignalSpy>
#include <QCoreApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <queue>
#include "gamehistory.h"

// Test isValidString function
void testIsValidString() {
    QVERIFY(isValidString("X12*O34*X56*O78*"));
    QVERIFY(isValidString("X12*O34*"));
    QVERIFY(isValidString("X12"));
    QVERIFY(isValidString(""));
    QVERIFY(!isValidString("X12*O34*?56*O78*")); // Invalid character '?'
    QVERIFY(!isValidString("X12*O34**O78*")); // Empty move between '*'
}

// Test splitAndEnqueue function
void testSplitAndEnqueue() {
    string moves = "X00*O11*X22*O01*X02*";
    queue<string> moveQueue = splitAndEnqueue(moves);

    QCOMPARE(moveQueue.size(), 5);
    QCOMPARE(moveQueue.front(), string("X00"));
    moveQueue.pop();
    QCOMPARE(moveQueue.front(), string("O11"));
    moveQueue.pop();
    QCOMPARE(moveQueue.front(), string("X22"));
    moveQueue.pop();
    QCOMPARE(moveQueue.front(), string("O01"));
    moveQueue.pop();
    QCOMPARE(moveQueue.front(), string("X02"));
}

// Test the gameHistory constructor
void testGameHistoryConstructor() {
    gameHistory history(nullptr, "X00*O11*X22*O01*X02*");
    QVERIFY(!history.moveQueue.empty());
}

// Test the on_pushButton_play_clicked slot
void testPushButtonPlayClicked() {
    gameHistory history(nullptr, "X00*O11*X22*O01*X02*");
    QPushButton* playButton = history.findChild<QPushButton*>("pushButton_play");
    QGridLayout* gridLayout = history.findChild<QGridLayout*>("gridOfMoves");
    QVERIFY(playButton != nullptr);
    QVERIFY(gridLayout != nullptr);

    QSignalSpy spy(playButton, &QPushButton::clicked);
    QVERIFY(spy.isValid());

    // Click the play button and check if moves are displayed correctly
    for (int i = 0; i < 5; ++i) {
        playButton->click();
        QVERIFY(spy.wait());

        QLabel* label = qobject_cast<QLabel*>(gridLayout->itemAtPosition(i / 3, i % 3)->widget());
        QVERIFY(label != nullptr);
        QCOMPARE(label->text(), QString(i % 2 == 0 ? "X" : "O"));
    }

    // Ensure play button is disabled after all moves are played
    QCOMPARE(playButton->isEnabled(), false);
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QApplication app(argc, argv);

    // Run the tests
    testIsValidString();
    testSplitAndEnqueue();
    testGameHistoryConstructor();
    testPushButtonPlayClicked();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
