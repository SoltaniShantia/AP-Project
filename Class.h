#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QMultiMap>
#include "dist/json/json.h"
#include "Enum.h"

class Class
{
public:

    Class(lesson lesson, QString teacher);
    Class(const Class &other);
    lesson getLesson();
    QString getTeacher();
    QString getLocation();
    QString getTime();
    day getDay();
    int getStudentNum();
    QMap < QString , float > getList();
//    QMap < QString , int > getSurveyResult();

    void setLocation(QString loc); //update file
    void setTime(QString time); //update file
    void setDay(day day); //update file
    void addStudent(QString student_username); //add record to file
    void deleteStudent(QString student_username); //check if student exists and delete record from file
    void setScore(QString student_username, float score); //update file
    bool studentIsValid(QString studentUsername);
//    void addSurveyResult(QString student_username , int result); //update file
    void setinformation(lesson lesson , QString location , QString time , day day , QMap<QString , float> students);

private:
    QString filePath;
    Json::Value dataHolder;
    Json::Reader dataReader;

    lesson lesson;
    QString teacher; //teacher username
    int number_of_students;

    QString location;
    QString time;
    day day;

    QMap < QString , float > studentslist;
//    QMap < QString , int > surveyresult;
    void setStudentScore(QString studentname,enum lesson lesson ,float newscore);

};
#endif // CLASS_H
