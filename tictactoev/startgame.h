#ifndef STARTGAME_H
#define STARTGAME_H

#include <QAudioOutput>
#include <QDialog>
#include <QGridLayout>
#include <QString>
#include <QtMultimedia>
#include <string>

namespace Ui {
class Startgame;
}

enum class Player { None, X, O };

class Startgame : public QDialog {
  Q_OBJECT

 public:
  explicit Startgame(QWidget *parent = nullptr, std::string p1 = "",
                     std::string p2 = "", int mode = 1, bool checked = false);
  ~Startgame();

 private slots:
  void handleButtonClick(int row, int col, QPushButton *button);
  void handleButtonClick2(int row, int col, QPushButton *button);
  bool CheckWin(Player player);
  bool CheckTie();
  void SaveGame();
  void on_checkBox_stateChanged(int arg1);

  void on_checkBox_2_stateChanged(int arg1);

 private:
  Ui::Startgame *ui;
  Player current_player_;
  Player grid_[3][3];
  Player ai_choice_ = Player::O;
  Player human_choice_ = Player::X;
  std::string player1_;
  std::string player2_;
  int game_mode_;
  QVector<QString> game_moves_;
  std::pair<int, int> AIMove();
  void AIFirst();
  int MiniMax(int depth, bool is_maximizer);
  int EvaluateBoard();
  int counter1_ = 0;
  int counter2_ = 0;
  int current_round_ = 1;
  static const int max_rounds_ = 3;
  bool save_ = false;

  void StartNextRound();
  QMediaPlayer *music_;
  QAudioOutput *audio_;

 protected:
  void closeEvent(QCloseEvent *event) override;
};

#endif  // STARTGAME_H
