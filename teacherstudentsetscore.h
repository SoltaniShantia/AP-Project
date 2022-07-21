#ifndef TEACHERSTUDENTSETSCORE_H
#define TEACHERSTUDENTSETSCORE_H

#include <QWidget>
#include <QGroupBox>

#include"teachermainmenu.h"

namespace Ui {
class TeacherStudentSetScore;
}

class TeacherStudentSetScore : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherStudentSetScore(TeacherMainMenu * member, Class thisClass , QWidget *parent = nullptr);
    ~TeacherStudentSetScore();
public slots:
    QGroupBox* showStudent(QString firstname,QString lastname,QString studentusername, Class thisClass);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_backToMenu_clicked();

    void SetScore_clicked(Class studentClass, QString S_username, float score);

private:
    float score;

    int numberOfStudents;

    Ui::TeacherStudentSetScore *ui;

    void setScore(int numberOfStudents, float score);

    TeacherMainMenu * mainmenu;
};

#endif // TEACHERSTUDENTSETSCORE_H
