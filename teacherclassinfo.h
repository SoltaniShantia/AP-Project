#ifndef TEACHERCLASSINFO_H
#define TEACHERCLASSINFO_H

#include <QWidget>
#include <QGroupBox>


#include"teachermainmenu.h"
namespace Ui {
class TeacherClassInfo;
}

class TeacherClassInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherClassInfo(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~TeacherClassInfo();
public slots:
    QGroupBox* watchClass(Class classToShow);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_backToMenu_clicked();

private:
    Ui::TeacherClassInfo *ui;
    void goToClassInfo(Class thisClass);

    TeacherMainMenu * mainmenu;
};

#endif // TEACHERCLASSINFO_H
