#ifndef ADMINMESSAGES_H
#define ADMINMESSAGES_H

#include <QWidget>

#include"adminmainmenu.h"

namespace Ui {
class adminMessages;
}

class adminMessages : public QWidget
{
    Q_OBJECT

public:
    explicit adminMessages(AdminMainMenu * reference , QWidget *parent = nullptr);
    ~adminMessages();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_msgbtn1_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::adminMessages *ui;
    AdminMainMenu * mainmenu;
};

#endif // ADMINMESSAGES_H
