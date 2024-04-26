#include "gamehistory.h"
#include "ui_gamehistory.h"

gameHistory::gameHistory(QWidget *parent, int mode)
    : QDialog(parent)
    , ui(new Ui::gameHistory)
{
    ui->setupUi(this);
    if (mode == 2)
        ui->pushButton_2->hide();

}

gameHistory::~gameHistory()
{
    delete ui;
}
