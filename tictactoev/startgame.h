#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>

namespace Ui {
class Startgame;
}

class Startgame : public QDialog
{
    Q_OBJECT

public:
    explicit Startgame(QWidget *parent = nullptr);
    ~Startgame();

private:
    Ui::Startgame *ui;
};

#endif // STARTGAME_H
