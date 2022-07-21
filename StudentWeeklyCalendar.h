#ifndef STUDENTWEEKLYCALENDAR_H
#define STUDENTWEEKLYCALENDAR_H

#include "WeeklyCalendar.h"


class StudentWeeklyCalendar : public WeeklyCalendar
{
public:
    StudentWeeklyCalendar();

    virtual void loadCalendar(QString username);

    virtual void addUser(Json::Value data);

    virtual void getCalendarDayByDay();

    virtual int isUserValid(QString username);

    virtual void addClass(QString username, Class Class);

    void removeClass(QString username, Class Class);
};

#endif // STUDENTWEEKLYCALENDAR_H
