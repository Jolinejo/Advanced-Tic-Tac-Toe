#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

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
                // Set the button text to "X" or "O" based on the current player's turn
                static bool isPlayerX = true;
                button->setText(isPlayerX ? "X" : "O");
                isPlayerX = !isPlayerX;
            });
        }
    }

    window.setLayout(layout);
    window.setWindowTitle("Tic Tac Toe");
    window.show();

    return app.exec();
}
