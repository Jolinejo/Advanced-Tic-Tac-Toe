#include "startgame.h"
#include "ui_startgame.h"

Startgame::Startgame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Startgame)
{
    ui->setupUi(this);
}

Startgame::~Startgame()
{
    delete ui;
}
