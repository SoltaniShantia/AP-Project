#ifndef TEACHERWEEKLYSCHEDULE_H
#define TEACHERWEEKLYSCHEDULE_H

#include <QWidget>

namespace Ui {
class teacherWeeklySchedule;
}

class teacherWeeklySchedule : public QWidget
{
    Q_OBJECT

public:
    explicit teacherWeeklySchedule(QWidget *parent = nullptr);
    ~teacherWeeklySchedule();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::teacherWeeklySchedule *ui;
};

#endif // TEACHERWEEKLYSCHEDULE_H
