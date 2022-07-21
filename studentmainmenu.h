#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QList>

#include "dist/json/json.h"
#include "Class.h"
#include "User.h"


namespace Ui {
class StudentMainMenu;
}

class StudentMainMenu : public User
{
    Q_OBJECT

public:
    explicit StudentMainMenu(QString firstname , QString username , StudentMainMenu * member = nullptr , QWidget *parent = nullptr);
    //if student exists read it from file else write new student : Term = 1
    ~StudentMainMenu();

    QList<float> getAverages();

    QMap <QString, float> getScores(int chosenTerm);

    // adds class at the end of term classes in file
    void registry(Class Class);

    // adds term into the list of target student in file
    void addTerm();

    // it should be called when student remove a Class or his/her teacher does
    void unregistery(Class Class);

//    bool is_equal(Class lesson);

    void surveyOfTeachers(Class Class , int result);
//    void deleteLesson(Class lesson);

    void load();

    bool createUserRecord();

    void finalizeRegistering();

    bool canRegister();

    QList<QMap<QString , QString>> getClasses(int chosenTerm);

    int getTerm ();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::StudentMainMenu *ui;

    QString filePath = "../data_resources/student_term.json";

    Json::Value dataHolder;

    Json::Reader dataReader;

    StudentMainMenu * mainmenu;

    int Term;

    float currentAverege;

    QList <float> avereges;

    QList<QMap<QString, QString>> classes;

//    QMap < QList <Class> , float> terms; //Averege: float

    // whenever the user wants to see the details of term this method will be called
    QList <Class> currentClasses;
};


#endif // STUDENTMAINMENU_H
