#ifndef GAMESLIST_H
#define GAMESLIST_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class gamesList;
}

class gamesList : public QDialog
{
    Q_OBJECT

public:
    explicit gamesList(QWidget *parent = nullptr, string player = "");
    ~gamesList();

private:
    Ui::gamesList *ui;
    string player;
};

#endif // GAMESLIST_H
