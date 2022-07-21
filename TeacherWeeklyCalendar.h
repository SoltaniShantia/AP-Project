#ifndef TEACHERWEEKLYCALENDAR_H
#define TEACHERWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"
#include "CalendarCreator.h"
#include <QString>
#include <QMap>
#include <QList>

class TeacherWeeklycalendar : public WeeklyCalendar
{
public:
    TeacherWeeklycalendar();

    virtual void loadCalendar(QString username);

    virtual void addUser(Json::Value data);

    virtual void getCalendarDayByDay();

    virtual int isUserValid(QString username);

    virtual void addClass(QString username, Class Class);

private:
    void createClass(QString username, Class Class);
};

#endif // TEACHERWEEKLYCALENDAR_H
