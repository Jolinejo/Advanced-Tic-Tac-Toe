#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>

namespace Ui {
class gameHistory;
}

class gameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit gameHistory(QWidget *parent = nullptr, int mode = 1);
    ~gameHistory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gameHistory *ui;
};

#endif // GAMEHISTORY_H
