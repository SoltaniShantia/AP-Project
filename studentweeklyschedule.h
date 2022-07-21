#ifndef STUDENTWEEKLYSCHEDULE_H
#define STUDENTWEEKLYSCHEDULE_H

#include <QWidget>

#include"studentmainmenu.h"

namespace Ui {
class studentWeeklySchedule;
}

using std::unique_ptr;

class studentWeeklySchedule : public QWidget
{
    Q_OBJECT

public:
    explicit studentWeeklySchedule(StudentMainMenu * member , QWidget *parent = nullptr);
    ~studentWeeklySchedule();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_refreshButton_clicked();

private:
    Ui::studentWeeklySchedule *ui;

    StudentMainMenu * mainmenu;

    void loadSchedule();

    unique_ptr<WeeklyCalendar> weeklyCalendar;
};

#endif // STUDENTWEEKLYSCHEDULE_H
