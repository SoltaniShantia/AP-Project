#ifndef TEACHERSENDASSERTION_H
#define TEACHERSENDASSERTION_H

#include <QWidget>

#include"teachermainmenu.h"

namespace Ui {
class TeacherSendAssertion;
}

class TeacherSendAssertion : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSendAssertion( TeacherMainMenu * tm = nullptr , QWidget *parent = nullptr);
    ~TeacherSendAssertion();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_sendbtn_clicked();

private:
    Ui::TeacherSendAssertion *ui;

    int studentsState;
    int teachersState;
    void studentReciveState(int state);
    void teacherReciveState(int state);
    TeacherMainMenu * mainmenu;
};

#endif // TEACHERSENDASSERTION_H
