#include "startgame.h"

#include <QApplication>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPushButton>
#include <ctime>
#include <fstream>
#include <iostream>

#include "mainwindow.h"
#include "ui_startgame.h"

std::string winner;

Startgame::Startgame(QWidget *parent, std::string p1, string p2, int mode)
    : QDialog(parent),
    ui(new Ui::Startgame),
    player1_(p1),
    player2_(p2),
    game_mode_(mode) {
    ui->setupUi(this);
    music_ = new QMediaPlayer();
    audio_ = new QAudioOutput();

    ui->label_round->setText("Round " + QString::number(current_round_));
    if (mode == 2) {
        ui->label_p2->setText("AI");  // Hide the whole button
        player2_ = "AI";
    } else {
        ui->label_p2->setText(QString::fromStdString(player2_) + " is O");
    }
    ui->label_p1->setText(QString::fromStdString(player1_) + " is X");

    // Initialize grid_ and currentPlayer
    current_player_ = Player::X;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid_[i][j] = Player::None;
        }
    }

    // Connect button clicks to appropriate handlers based on game mode
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = qobject_cast<QPushButton *>(
                ui->gridLayout_play->itemAtPosition(row, col)->widget());
            if (mode == 1) {
                connect(button, &QPushButton::clicked,
                        [=]() { handleButtonClick(row, col, button); });
            } else if (mode == 2) {
                connect(button, &QPushButton::clicked,
                        [=]() { handleButtonClick2(row, col, button); });
            }
        }
    }
}

Startgame::~Startgame() { delete ui; }

void Startgame::handleButtonClick(int row, int col, QPushButton *button) {
    // Handle player's move
    ui->checkBox->setVisible(false);
    if (grid_[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid_[row][col] = current_player_;
    QString text = (current_player_ == Player::X) ? "X" : "O";
    button->setText(text);
    button->setEnabled(false);
    if (save_) {
        game_moves_.push_back(text + QString::number(row) + QString::number(col));
    }

    if (CheckWin(current_player_)) {
        if (current_player_ == Player::X) {
            counter1_ = counter1_ + 1;
            winner = player1_;
            ui->lcdNumber_p1->display(QString::number(counter1_));
        } else {
            counter2_ = counter2_ + 1;
            winner = player2_;
            ui->lcdNumber_p2->display(QString::number(counter2_));
        }
        if (save_) SaveGame();
        StartNextRound();  // Start the next round
    } else if (CheckTie()) {
        winner = "tie";
        if (save_) SaveGame();
        StartNextRound();
    } else {
        // Switch to the other player's turn
        current_player_ = (current_player_ == Player::X) ? Player::O : Player::X;
    }
}

void Startgame::StartNextRound() {
    ++current_round_;
    ui->checkBox->setVisible(true);
    if (current_round_ > max_rounds_) {
        if (counter1_ > counter2_) {
            // Inside your function or constructor where you want to play the media
            music_->setSource(QUrl("qrc:/sounds/forx.mp3"));
            music_->setAudioOutput(audio_);
            audio_->setVolume(0.5);
            music_->play();
            QMessageBox::information(
                this, "Game Over",
                QString("%1 wins!").arg(QString::fromStdString(player1_)));
            close();
        } else if (counter2_ > counter1_) {
            music_->setSource(QUrl("qrc:/sounds/foro.mp3"));
            music_->setAudioOutput(audio_);
            audio_->setVolume(0.5);
            music_->play();
            QMessageBox::information(
                this, "Game Over",
                QString("%1 wins!").arg(QString::fromStdString(player2_)));
            close();
        } else {
            QMessageBox::information(this, "Game Over", QString("It's a tie!"));
            close();
        }
    }

    ui->label_round->setText("Round " + QString::number(current_round_));
    current_player_ = Player::X;
    // Clear the grid and gameMoves vectors
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid_[i][j] = Player::None;
        }
    }
    game_moves_.clear();

    // Clear the button texts and enable them
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = qobject_cast<QPushButton *>(
                ui->gridLayout_play->itemAtPosition(row, col)->widget());
            button->setText("");
            button->setEnabled(true);
        }
    }
}

void Startgame::handleButtonClick2(int row, int col, QPushButton *button) {
    // Handle player's move
    if (grid_[row][col] != Player::None) {
        // The button has already been clicked, ignore it
        return;
    }

    grid_[row][col] = current_player_;
    QString text = (current_player_ == Player::X) ? "X" : "O";
    button->setText(text);
    button->setEnabled(false);
    game_moves_.push_back(text + QString::number(row) + QString::number(col));

    if (CheckWin(current_player_)) {
        if (current_player_ == Player::X) {
            counter1_ = counter1_ + 1;
            winner = player1_;
            ui->lcdNumber_p1->display(QString::number(counter1_));
        } else {
            counter2_ = counter2_ + 1;
            winner = player2_;
            ui->lcdNumber_p2->display(QString::number(counter2_));
        }

        if (save_) SaveGame();
        StartNextRound();  // Start the next round
    } else if (CheckTie()) {
        winner = "tie";
        if (save_) SaveGame();
        StartNextRound();
    } else {
        // Switch to the other player's turn
        current_player_ = (current_player_ == Player::X) ? Player::O : Player::X;

        // AI's move
        pair<int, int> ai_move_coords = AIMove();
        grid_[ai_move_coords.first][ai_move_coords.second] = current_player_;
        QPushButton *aiButton = qobject_cast<QPushButton *>(
            ui->gridLayout_play
                ->itemAtPosition(ai_move_coords.first, ai_move_coords.second)
                ->widget());

        aiButton->setText((current_player_ == Player::X) ? "X" : "O");
        aiButton->setEnabled(false);
        if (save_)
            game_moves_.push_back(aiButton->text() +
                                  QString::number(ai_move_coords.first) +
                                  QString::number(ai_move_coords.second));

        if (CheckWin(current_player_)) {
            if (current_player_ == Player::X) {
                counter1_ = counter1_ + 1;
                winner = player1_;
                ui->lcdNumber_p1->display(QString::number(counter1_));
            } else {
                counter2_ = counter2_ + 1;
                winner = player2_;
                ui->lcdNumber_p2->display(QString::number(counter2_));
            }
            if (save_) SaveGame();
            StartNextRound();  // Start the next round
        } else if (CheckTie()) {
            winner = "tie";
            if (save_) SaveGame();
            StartNextRound();
        } else {
            // Switch to the other player's turn
            current_player_ = (current_player_ == Player::X) ? Player::O : Player::X;
        }
    }
}

pair<int, int> Startgame::AIMove() {
    int best_score = INT_MIN;
    pair<int, int> best_move = make_pair(-1, -1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid_[i][j] == Player::None) {
                grid_[i][j] = current_player_;  // Assume AI is always 'O' for
                    // minimization in this example
                int score = MiniMax(0, false);
                grid_[i][j] = Player::None;
                if (score > best_score) {
                    best_score = score;
                    best_move = make_pair(i, j);
                }
            }
        }
    }
    return best_move;
}

bool Startgame::CheckWin(Player player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (grid_[i][0] == player && grid_[i][1] == player && grid_[i][2] == player)
            return true;
        // Check columns
        if (grid_[0][i] == player && grid_[1][i] == player && grid_[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((grid_[0][0] == player && grid_[1][1] == player &&
         grid_[2][2] == player) ||
        (grid_[0][2] == player && grid_[1][1] == player && grid_[2][0] == player))
        return true;

    return false;
}

bool Startgame::CheckTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (grid_[i][j] == Player::None) return false;
    }
    return true;
}

int Startgame::MiniMax(int depth, bool is_maximizing_player) {
    int score = EvaluateBoard();

    if (score != 0) return score;
    if (CheckTie()) return 0;

    if (is_maximizing_player) {
        int best_score = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid_[i][j] == Player::None) {
                    grid_[i][j] = Player::O;
                    best_score = max(best_score, MiniMax(depth + 1, false));
                    grid_[i][j] = Player::None;
                }
            }
        }
        return best_score;
    } else {
        int best_score = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid_[i][j] == Player::None) {
                    grid_[i][j] = Player::X;
                    best_score = min(best_score, MiniMax(depth + 1, true));
                    grid_[i][j] = Player::None;
                }
            }
        }
        return best_score;
    }
}

int Startgame::EvaluateBoard() {
    if (CheckWin(Player::O)) {
        return 10;  // PLAYER_X wins
    } else if (CheckWin(Player::X)) {
        return -10;  // PLAYER_O wins
    } else {
        return 0;  // Game not over
    }
}

void Startgame::SaveGame() {
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::string concatenatedString =
        std::string(timestamp) + "*" + player1_ + "*" + player2_ + "*" + winner;
    for (const auto &move : game_moves_) {
        concatenatedString = concatenatedString + "*" + move.toStdString();
    }
    std::ofstream file(GetPath("/history.txt").toStdString(), std::ios::app);
    if (file.is_open()) {
        file << concatenatedString << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

void Startgame::on_checkBox_stateChanged(int arg1) {
    if (arg1 == Qt::Checked) {
        save_ = true;
    } else {
        save_ = false;
    }
}
