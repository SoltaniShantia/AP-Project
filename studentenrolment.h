#ifndef STUDENTENROLMENT_H
#define STUDENTENROLMENT_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>

#include"studentmainmenu.h"
namespace Ui {
class StudentEnrolment;
}

class StudentEnrolment : public QWidget
{
    Q_OBJECT

public:
    explicit StudentEnrolment(StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentEnrolment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();

    void registeryStatus(Class classToShow, QCheckBox * selection);

public slots:
    QGroupBox* showLessons(Class classToShow);
private:
    Ui::StudentEnrolment *ui;
    StudentMainMenu * mainmenu ;
};

#endif // STUDENTENROLMENT_H
