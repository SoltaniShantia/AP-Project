#ifndef TEACHERWEEKLYSCHEDULE_H
#define TEACHERWEEKLYSCHEDULE_H

#include <QWidget>

#include"teachermainmenu.h"
#include "WeeklyCalendar.h"

namespace Ui {
class teacherWeeklySchedule;
}

using std::unique_ptr, std::make_unique;

class teacherWeeklySchedule : public QWidget
{
    Q_OBJECT

public:
    explicit teacherWeeklySchedule(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~teacherWeeklySchedule();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_backToMenu_clicked();

    void on_refreshButton_clicked();

private:
    Ui::teacherWeeklySchedule *ui;

    TeacherMainMenu * mainmenu;

    void loadSchedule();

    unique_ptr<WeeklyCalendar> weeklyCalendar;
};

#endif // TEACHERWEEKLYSCHEDULE_H
