
#include <QtTest>
#include <QSignalSpy>
#include <QCoreApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QMessageBox>
#include <ctime>
#include <fstream>
#include "dialog.h"

// Test the handleButtonClick function
void testHandleButtonClick() {
    QPushButton* button = new QPushButton();
    button->setEnabled(true);

    // Simulate a button click
    handleButtonClick(0, 0, button);

    // After clicking, the button text should be "X"
    QCOMPARE(button->text(), QString("X"));
    // After clicking, the button should be disabled
    QCOMPARE(button->isEnabled(), false);
}

// Test the checkWin function
void testCheckWin() {
    grid[0][0] = grid[0][1] = grid[0][2] = Player::X;
    QCOMPARE(checkWin(Player::X), true);

    // Reset the grid for further tests
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = Player::None;
        }
    }

    grid[0][0] = grid[1][0] = grid[2][0] = Player::O;
    QCOMPARE(checkWin(Player::O), true);
}

// Test the checkTie function
void testCheckTie() {
    // Fill the grid with X and O alternatively
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = (i + j) % 2 == 0 ? Player::X : Player::O;
        }
    }
    // The grid is full, so it should be a tie
    QCOMPARE(checkTie(), true);
}

// Test the saveGame function
void testSaveGame() {
    // Initialize gameMoves
    gameMoves = {"X00", "O01", "X02", "O10", "X11"};

    // Call the saveGame function
    saveGame();

    // Check if the game history file is created and contains the correct data
    std::ifstream file(getPath("/history.txt").toStdString());
    std::string line;
    std::getline(file, line);
    QVERIFY(!line.empty());
    file.close();
}

// Test the execution of the game
void testExecuteGame() {
    // Initialize a Dialog object
    Dialog dialog;
    dialog.setModal(true);

    // Simulate clicking the start game button
    dialog.on_pushButton_clicked();

    // Find all buttons in the layout
    QGridLayout* layout = dialog.findChild<QGridLayout*>("gridLayout");
    QVERIFY(layout != nullptr);

    QList<QPushButton*> buttons = dialog.findChildren<QPushButton*>();
    QVERIFY(buttons.size() == 9); // 3x3 grid

    // Simulate clicking all buttons
    for (auto button : buttons) {
        QSignalSpy spy(button, &QPushButton::clicked);
        QVERIFY(spy.isValid());
        button->click();
        QVERIFY(spy.wait());
    }
}

// Test the Dialog constructor
void testDialogConstructor() {
    Dialog dialog(nullptr, 1, "Player 1", "Player 2");

    // Check if the button text is set correctly
    QCOMPARE(dialog.findChild<QPushButton*>("pushButton_display1")->text(), QString("Player 1's history"));
    QCOMPARE(dialog.findChild<QPushButton*>("pushButton_display2")->text(), QString("Player 2's history"));
}

// Test the Dialog pushButton_display1_clicked slot
void testPushButtonDisplay1Clicked() {
    Dialog dialog(nullptr, 1, "Player 1", "Player 2");

    // Simulate clicking the display1 button
    dialog.on_pushButton_display1_clicked();

    // Check if the gamesList dialog is opened
    QVERIFY(dialog.games != nullptr);
}

// Test the Dialog pushButton_display2_clicked slot
void testPushButtonDisplay2Clicked() {
    Dialog dialog(nullptr, 2, "Player 1", "Player 2");

    // Simulate clicking the display2 button
    dialog.on_pushButton_display2_clicked();

    // Check if the gamesList dialog is opened
    QVERIFY(dialog.games != nullptr);
}

// Define a custom test main to avoid conflicts with Qt framework
int main(int argc, char *argv[]) {
    // Initialize Qt application
    QApplication app(argc, argv);

    // Run the tests
    testHandleButtonClick();
    testCheckWin();
    testCheckTie();
    testSaveGame();
    testExecuteGame();
    testDialogConstructor();
    testPushButtonDisplay1Clicked();
    testPushButtonDisplay2Clicked();

    // Close the application
    return QTest::qExec(&app, argc, argv);
}
