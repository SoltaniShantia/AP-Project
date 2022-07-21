#ifndef CALENDARCREATOR_H
#define CALENDARCREATOR_H

#include "dist/json/json.h"
#include "Class.h"

#include <QString>
#include <QList>
#include <QMap>

class CalendarCreator
{
private:
    QList<QMap<QString, QString>> classList;
    Json::Value jsonCalendar;

public:
    CalendarCreator();

    CalendarCreator(Json::Value userData);

    void setUsername(QString username);

    void append(Class Class);

    const Json::Value exportJson() const;
};

#endif // CALENDARCREATOR_H
