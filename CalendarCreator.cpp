#include "CalendarCreator.h"
#include "Enum.h"

CalendarCreator::CalendarCreator()
{
    Json::Value initData;

    initData["username"] = Json::stringValue;

    initData["classes"] = Json::arrayValue;

    jsonCalendar = initData;

    return;
}

CalendarCreator::CalendarCreator(Json::Value userData)
{
    jsonCalendar = userData;

    return;
}

void CalendarCreator::setUsername(QString username)
{
    jsonCalendar["username"] = username.toStdString();

    return;
}

void CalendarCreator::append(Class Class)
{
    Json::Value modifiedClasses = jsonCalendar["classes"];

    Json::Value classData;

    classData["day"] = day_enum_str[Class.getDay()].toStdString();

    classData["time"] = Class.getTime().toStdString();

    classData["name"] = lesson_enum_str[Class.getLesson()].toStdString();

    modifiedClasses.append(classData);

    jsonCalendar["classes"] = modifiedClasses;

    return;
}

const Json::Value CalendarCreator::exportJson() const
{
    return jsonCalendar;
}



