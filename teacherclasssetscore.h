#ifndef TEACHERCLASSSETSCORE_H
#define TEACHERCLASSSETSCORE_H

#include <QWidget>
#include <QGroupBox>

#include"teachermainmenu.h"

namespace Ui {
class TeacherClassSetScore;
}

class TeacherClassSetScore : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherClassSetScore(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~TeacherClassSetScore();
public slots:
    QGroupBox* watchClass(Class classToShow);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_backToMenu_clicked();

private:
    Ui::TeacherClassSetScore *ui;
    void goToClassInfo(Class thisClass);

    TeacherMainMenu * mainmenu;
};

#endif // TEACHERCLASSSETSCORE_H
