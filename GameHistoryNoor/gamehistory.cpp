#include "gamehistory.h"
#include "ui_gamehistory.h"
#include <QGridLayout>
#include <QLabel>

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

void gameHistory::on_pushButton_clicked()
{
    // Assuming you have access to the relevant game data
    QStringList player1Moves = { "x12", "x00", "x22" };  // Example player 1 moves
    QStringList player2Moves = { "o11", "o02", "o21" };  // Example player 2 moves

    // Create a grid layout to represent the tic-tac-toe board
    QGridLayout *gridLayout = new QGridLayout(ui->scrollAreaWidgetContents);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    // Define the size of the tic-tac-toe grid
    const int gridSize = 3;

    // Create and initialize the grid with empty cells
    QVector<QLabel *> gridCells(gridSize * gridSize);
    for (int i = 0; i < gridSize * gridSize; ++i) {
        QLabel *label = new QLabel("", ui->scrollAreaWidgetContents);
        label->setAlignment(Qt::AlignCenter);
        gridLayout->addWidget(label, i / gridSize, i % gridSize);
        gridCells[i] = label;
    }

    // Populate the grid with player moves
    for (int i = 0; i < player1Moves.size() || i < player2Moves.size(); ++i) {
        // Add player 1 move if available
        if (i < player1Moves.size()) {
            QString move = player1Moves.at(i);
            int row = move.mid(1, 1).toInt();
            int col = move.mid(2, 1).toInt();
            gridCells[row * gridSize + col]->setText("X");
        }

        // Add player 2 move if available
        if (i < player2Moves.size()) {
            QString move = player2Moves.at(i);
            int row = move.mid(1, 1).toInt();
            int col = move.mid(2, 1).toInt();
            gridCells[row * gridSize + col]->setText("O");
        }
    }

    // Set the grid layout as the layout for the scroll area widget
    ui->scrollAreaWidgetContents->setLayout(gridLayout);
}


