#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include <QWidget>

#include"studentmainmenu.h"

namespace Ui {
class StudentProfile;
}

class StudentProfile : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProfile(StudentMainMenu * member, QWidget *parent = nullptr);
    ~StudentProfile();

private slots:
    void on_chngNumber_clicked();

    void on_chngPass_clicked();

    void on_applychng_clicked();

    void on_applychng_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentProfile *ui;
    StudentMainMenu * mainmenu;
};

#endif // STUDENTPROFILE_H
