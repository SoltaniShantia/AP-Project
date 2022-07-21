#ifndef WEEKLYCALENDAR_H
#define WEEKLYCALENDAR_H

#include "dist/json/json.h"
#include "Class.h"
#include "CalendarCreator.h"

#include <QString>
#include <QList>
#include <QMap>

class WeeklyCalendar
{
private:
    bool isClassExist(Json::Value classData);

protected:
    Json::Value dataHolder;
    Json::Reader dataReader;
    QList<QMap<QString, QString>> calendar;

    QList<QList<QMap<QString, QString>>> seperatedCalendar;

    QString filePath = "../data_resources/weeklycalendar.json";

public:
    WeeklyCalendar();

    virtual void loadCalendar(QString username) = 0;

    // initialize data for calendar
    virtual void addUser(Json::Value data) = 0;

    // get calendar for each day and put it in seperate list
    virtual void getCalendarDayByDay() = 0;

    virtual int isUserValid(QString username) = 0;

    virtual void addClass(QString username, Class Class) = 0;

    const QList<QMap<QString, QString> > &getCalendar() const;

    // name is the name of class(class means learning class)
    Json::Value formClassData(QString name, QString day, QString time);

    // adds class to target user based on username and user role
    void appendClass(Json::Value newClass, QString username, QString role);

    // deletes class from target user based on class name
    void deleteClass(Class Class, QString username, QString role);

    const QList<QList<QMap<QString, QString> > > &getSeperatedCalendar() const;
};

#endif // WEEKLYCALENDAR_H
