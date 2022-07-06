#ifndef TEACHERWATCHSTUDENT_H
#define TEACHERWATCHSTUDENT_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class TeacherWatchStudent;
}

class TeacherWatchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWatchStudent(QWidget *parent = nullptr);
    ~TeacherWatchStudent();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TeacherWatchStudent *ui;

    QGroupBox* students();
};

#endif // TEACHERWATCHSTUDENT_H
