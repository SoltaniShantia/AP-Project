#include "TeacherWeeklyCalendar.h"

#include <fstream>


using namespace std;

TeacherWeeklycalendar::TeacherWeeklycalendar()
    : WeeklyCalendar()
{
    return;
}

void TeacherWeeklycalendar::loadCalendar(QString username)
{
    ifstream ifs(filePath.toStdString());

    // clear(empty) calendar before filling it with new data
    calendar.clear();

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teacherClasses = dataHolder["teachers"];

        for(int i = 0; i < teacherClasses.size(); i++)
        {
            if(teacherClasses[i]["username"].asString() == username.toStdString())
            {
                Json::Value wantedTeacherClasses = teacherClasses[i]["classes"];

                for(int j = 0; j < wantedTeacherClasses.size(); j++)
                {
                    QMap<QString, QString> classData;

                    classData.insert("name", QString::fromStdString(wantedTeacherClasses[j]["name"].asString()));
                    classData.insert("day", QString::fromStdString(wantedTeacherClasses[j]["day"].asString()));
                    classData.insert("time", QString::fromStdString(wantedTeacherClasses[j]["time"].asString()));

                    calendar.push_back(classData);
                }
            }
        }
    }
}

void TeacherWeeklycalendar::addUser(Json::Value data)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value dataHolderCopy = dataHolder["teachers"];

        dataHolderCopy.append(data);

        dataHolder["teachers"] = dataHolderCopy;

        Json::StyledWriter writer;

        ofstream jsonWriter(filePath.toStdString());

        string serializedData = writer.write(dataHolder);

        jsonWriter << serializedData;

        jsonWriter.close();
    }
}

void TeacherWeeklycalendar::getCalendarDayByDay()
{
    QList<QList<QMap<QString, QString>>> seperatedDays;

    QList<QMap<QString, QString>> Saturday;
    QList<QMap<QString, QString>> Sunday;
    QList<QMap<QString, QString>> Monday;
    QList<QMap<QString, QString>> Tuesday;
    QList<QMap<QString, QString>> Wednsday;
    QList<QMap<QString, QString>> Thursday;
    QList<QMap<QString, QString>> Friday;

    for(auto calendarItem : calendar)
    {
        if(calendarItem["day"] == "Saturday")
            Saturday.push_back(calendarItem);
        else if(calendarItem["day"] == "Sunday")
            Sunday.push_back(calendarItem);
        else if(calendarItem["day"] == "Monday")
            Monday.push_back(calendarItem);
        else if(calendarItem["day"] == "Tuesday")
            Tuesday.push_back(calendarItem);
        else if(calendarItem["day"] == "Wednsday")
            Wednsday.push_back(calendarItem);
        else if(calendarItem["day"] == "Thursday")
            Thursday.push_back(calendarItem);
        else
            Friday.push_back(calendarItem);
    }

    seperatedDays.push_back(Saturday);
    seperatedDays.push_back(Sunday);
    seperatedDays.push_back(Monday);
    seperatedDays.push_back(Tuesday);
    seperatedDays.push_back(Wednsday);
    seperatedDays.push_back(Thursday);
    seperatedDays.push_back(Friday);

    this->seperatedCalendar = seperatedDays;
}

int TeacherWeeklycalendar::isUserValid(QString username)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teachers = dataHolder["teachers"];

        for(int i = 0; i < teachers.size(); i++)
        {
            if(username.toStdString() == teachers[i]["username"].asString())
                return i;
        }
    }

    return -1;
}

void TeacherWeeklycalendar::addClass(QString username, Class Class)
{
    ifstream ifs(filePath.toStdString());

    unique_ptr<CalendarCreator> calendarCreator;

    if(dataReader.parse(ifs, dataHolder))
    {
        int userIndex = isUserValid(username);

        if(userIndex == -1)
        {
            calendarCreator.reset(new CalendarCreator);

            calendarCreator.get()->append(Class);

            calendarCreator.get()->setUsername(username);

            dataHolder["teachers"].append(calendarCreator.get()->exportJson());
        }
        else
        {
            calendarCreator.reset(new CalendarCreator(dataHolder["teachers"][userIndex]));

            calendarCreator.get()->append(Class);

            dataHolder["teachers"][userIndex] = calendarCreator.get()->exportJson();

        }

        ofstream ofs(filePath.toStdString());

        Json::StyledWriter writer;

        string serializedData = writer.write(dataHolder);

        ofs << serializedData;

        ofs.close();
    }

}

void TeacherWeeklycalendar::createClass(QString username, Class Class)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teachers = dataHolder["teachers"];

        for(int i = 0; i < teachers.size(); i++)
        {
            Json::Value teacher = teachers[i];

            if(username.toStdString() == teacher["username"].asString())
            {
                Json::Value classes = teacher["classes"];

                Json::Value newClass;

                newClass["day"] = lesson_enum_str[Class.getDay()].toStdString();

                newClass["time"] = Class.getTime().toStdString();

                newClass["name"] = day_enum_str[Class.getLesson()].toStdString();

                classes.append(newClass);

                dataHolder["teachers"][i]["classes"] = classes;

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}



