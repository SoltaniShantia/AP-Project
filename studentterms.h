#ifndef STUDENTTERMS_H
#define STUDENTTERMS_H

#include <QWidget>
#include <QGroupBox>


#include"studentmainmenu.h"
namespace Ui {
class StudentTerms;
}

class StudentTerms : public QWidget
{
    Q_OBJECT

public:
    explicit StudentTerms(StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentTerms();
public slots:
    QGroupBox* showTerms(int term);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::StudentTerms *ui;

    void goToScores(int term);

    StudentMainMenu * mainmenu;
};

#endif // STUDENTTERMS_H
