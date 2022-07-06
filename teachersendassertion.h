#ifndef TEACHERSENDASSERTION_H
#define TEACHERSENDASSERTION_H

#include <QWidget>

namespace Ui {
class TeacherSendAssertion;
}

class TeacherSendAssertion : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSendAssertion(QWidget *parent = nullptr);
    ~TeacherSendAssertion();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TeacherSendAssertion *ui;

    int studentsState;
    void studentReciveState(int state);
};

#endif // TEACHERSENDASSERTION_H
