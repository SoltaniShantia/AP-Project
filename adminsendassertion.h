#ifndef ADMINSENDASSERTION_H
#define ADMINSENDASSERTION_H

#include <QWidget>

#include"adminmainmenu.h"

namespace Ui {
class AdminSendAssertion;
}

class AdminSendAssertion : public QWidget
{
    Q_OBJECT

public:
    explicit AdminSendAssertion(AdminMainMenu * recievedmember = nullptr , QWidget *parent = nullptr);
    ~AdminSendAssertion();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_sendbtn_clicked();

private:
    Ui::AdminSendAssertion *ui;
    int adminsState;
    int studentsState;
    int teachersState;
    AdminMainMenu * mainmenu ;
    void adminReciveState(int state);
    void studentReciveState(int state);
    void teacherReciveState(int state);
};

#endif // ADMINSENDASSERTION_H
