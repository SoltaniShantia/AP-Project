#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>

#include"User.h"

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public User
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QString firstName , AdminMainMenu * member = nullptr , QWidget *parent = nullptr);
    ~AdminMainMenu();


public slots:
    void ending_term();



private slots:
    void on_pushButton_5_clicked();


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::AdminMainMenu *ui;

    AdminMainMenu * mainmenu;
};

#endif // ADMINMAINMENU_H
//having a def to change the button accessibility to the arzeshyabi part
