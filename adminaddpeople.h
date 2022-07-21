#ifndef ADMINADDPEOPLE_H
#define ADMINADDPEOPLE_H

#include <QWidget>

#include"adminmainmenu.h"

namespace Ui {
class AdminAddPeople;
}

class AdminAddPeople : public QWidget
{
    Q_OBJECT

public:
    explicit AdminAddPeople(AdminMainMenu * member , QWidget *parent = nullptr);
    ~AdminAddPeople();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_AddBtn_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::AdminAddPeople *ui;
    AdminMainMenu * mainmenu;
};

#endif // ADMINADDPEOPLE_H
