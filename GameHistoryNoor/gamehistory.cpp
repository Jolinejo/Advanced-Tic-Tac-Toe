#include "gamehistory.h"
#include "ui_gamehistory.h"
#include <QGridLayout>
#include <QLabel>
#include <iostream>
#include <thread>
#include <chrono>
#include <QTimer>


gameHistory::gameHistory(QWidget *parent, int mode) :
    QDialog(parent),
    ui(new Ui::gameHistory)
{
    ui->setupUi(this);
    if (mode == 2)
        ui->pushButton->hide();
}

gameHistory::~gameHistory()
{
    delete ui;
}
QStringList player1Moves = { "x12", "x00", "x22" };  // Example player 1 moves
QStringList player2Moves = { "o11", "o02", "o21" };  // Example player 2 moves
// Declare member variables to keep track of game state
int moveIndex = 0; // Index of the next move to be displayed

// Slot function for handling button click
void gameHistory::on_pushButton_clicked()
{
    // Check if there are any moves left to display
    if (moveIndex < player1Moves.size() + player2Moves.size()) {
        // Determine which player's move to display based on moveIndex
        QString move;
        if (moveIndex % 2 == 0) {
            // Player 1's move
            move = player1Moves[moveIndex / 2];
        } else {
            // Player 2's move
            move = player2Moves[moveIndex / 2];
        }

        // Extract row and column information from the move string
        int row = move.mid(1, 1).toInt();
        int col = move.mid(2, 1).toInt();

        // Find the label corresponding to the row and column
        QString labelName = QString("label_%1").arg(row * 3 + col + 1);
        QLabel *label = ui->scrollAreaWidgetContents->findChild<QLabel*>(labelName);

        // Populate the label with "X" or "O"
        if (label) {
            if (moveIndex % 2 == 0) {
                // Player 1's move
                label->setText("X");
            } else {
                // Player 2's move
                label->setText("O");
            }
        }

        // Increment moveIndex for the next move
        moveIndex++;
    } else {
        // If no moves left, disable the button
        ui->pushButton->setEnabled(false);
    }
}


