#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, int mode = 1, string p1 = "", string p2 = "");
    ~Dialog();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Dialog *ui;
    int gameMode;
    string player1;
    string player2;
};

void executeAi(string player);
#endif // DIALOG_H
