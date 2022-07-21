#ifndef STUDENTTERMSCORES_H
#define STUDENTTERMSCORES_H

#include <QWidget>
#include <QGroupBox>

#include"studentmainmenu.h"

namespace Ui {
class StudentTermScores;
}

class StudentTermScores : public QWidget
{
    Q_OBJECT

public:
    explicit StudentTermScores(int term , StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentTermScores();
public slots:
    QGroupBox* showScores(int lessonNumber , int term);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::StudentTermScores *ui;
    StudentMainMenu * mainmenu ;
};

#endif // STUDENTTERMSCORES_H
