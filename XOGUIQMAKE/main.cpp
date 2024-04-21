#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

enum class Player {
    None,
    X,
    O
};

Player currentPlayer = Player::X;
Player grid[3][3] = { { Player::None, Player::None, Player::None },
                     { Player::None, Player::None, Player::None },
                     { Player::None, Player::None, Player::None } };

bool checkWin(Player player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        // Check columns
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
        return true;

    return false;
}


void handleButtonClick(int row, int col, QPushButton* button)
{
    if (grid[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid[row][col] = currentPlayer;
    button->setText(currentPlayer == Player::X ? "X" : "O");
    button->setEnabled(false);

    if (checkWin(currentPlayer)) {
        QMessageBox::information(nullptr, "Game Over", QString("%1 wins!").arg(currentPlayer == Player::X ? "X" : "O"));
        QApplication::quit();
    } else {
        // Switch to the other player's turn
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QGridLayout* layout = new QGridLayout(&window);

    const int gridSize = 3;
    QPushButton* buttons[gridSize][gridSize];

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            QPushButton* button = new QPushButton(&window);
            button->setFixedSize(100, 100); // Adjust the button size as needed
            layout->addWidget(button, row, col);
            buttons[row][col] = button;

            QAbstractButton::connect(button, &QPushButton::clicked, [=]() {
                handleButtonClick(row, col, button);
            });
        }
    }

    window.setLayout(layout);
    window.setWindowTitle("Tic Tac Toe");
    window.show();

    return app.exec();
}
