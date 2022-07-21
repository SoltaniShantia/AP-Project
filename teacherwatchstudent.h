#ifndef TEACHERWATCHSTUDENT_H
#define TEACHERWATCHSTUDENT_H

#include <QWidget>
#include <QGroupBox>

#include"teachermainmenu.h"

namespace Ui {
class TeacherWatchStudent;
}

class TeacherWatchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWatchStudent(TeacherMainMenu * member ,Class thisClass,  QWidget *parent = nullptr);
    ~TeacherWatchStudent();

private slots:
    void on_backToMenu_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void removeStudent_clicked(Class thisClass,QString studentusername);

private:
    Ui::TeacherWatchStudent *ui;

    QGroupBox* students(QString firstname,QString lastname,QString studentusername, Class thisClass);

    TeacherMainMenu * mainmenu ;
};

#endif // TEACHERWATCHSTUDENT_H
