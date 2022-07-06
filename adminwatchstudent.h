#ifndef ADMINWATCHSTUDENT_H
#define ADMINWATCHSTUDENT_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class AdminWatchStudent;
}

class AdminWatchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWatchStudent(QWidget *parent = nullptr);
    ~AdminWatchStudent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_backToMenu_clicked();

private:
    Ui::AdminWatchStudent *ui;
    QGroupBox* students();
};

#endif // ADMINWATCHSTUDENT_H
