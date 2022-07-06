#ifndef STUDENTWEEKLYSCHEDULE_H
#define STUDENTWEEKLYSCHEDULE_H

#include <QWidget>

namespace Ui {
class studentWeeklySchedule;
}

class studentWeeklySchedule : public QWidget
{
    Q_OBJECT

public:
    explicit studentWeeklySchedule(QWidget *parent = nullptr);
    ~studentWeeklySchedule();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

private:
    Ui::studentWeeklySchedule *ui;
};

#endif // STUDENTWEEKLYSCHEDULE_H
