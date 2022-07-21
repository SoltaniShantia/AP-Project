#ifndef STUDENTWATCHSURVEY_H
#define STUDENTWATCHSURVEY_H

#include <QWidget>


#include"studentmainmenu.h"
namespace Ui {
class StudentWatchSurvey;
}

class StudentWatchSurvey : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWatchSurvey(QString tUsername , QString ls , StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentWatchSurvey();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_setScore_clicked();

private:
    Ui::StudentWatchSurvey *ui;

    StudentMainMenu * mainmenu ;
    QString teacherUsername ;
    QString lesson ;
    int score ;

};

#endif // STUDENTWATCHSURVEY_H
