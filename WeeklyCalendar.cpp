#include "WeeklyCalendar.h"
#include "Enum.h"

#include <iostream>
#include <fstream>

using namespace std;

bool WeeklyCalendar::isClassExist(Json::Value classData)
{
    QString classDataName = QString::fromStdString(classData["name"].asString());

    for(int i = 0; i < calendar.size(); i++)
    {
        if(calendar[i]["name"] == classDataName)
            return true;
    }

    return false;
}

const QList<QList<QMap<QString, QString> > > &WeeklyCalendar::getSeperatedCalendar() const
{
    return seperatedCalendar;
}

WeeklyCalendar::WeeklyCalendar()
{
    // these few line(to the if statement) checks wether file exists or not if it exists construcor won't init data
    ifstream ifs(filePath.toStdString());

    if(ifs)
    {
        cout << "Json File Found..." << endl;

        return;
    }

    // to form base json structor
    Json::Value baseData;

    // an empty list for each role(teachers, admins, students)
    baseData["teachers"] = Json::arrayValue;
    baseData["students"] = Json::arrayValue;
    baseData["admins"] = Json::arrayValue;

    Json::StyledWriter writer;

    ofstream jsonWriter(filePath.toStdString());

    string serializedData = writer.write(baseData);

    jsonWriter << serializedData;

    jsonWriter.close();

    return;
}

const QList<QMap<QString, QString>> &WeeklyCalendar::getCalendar() const
{
    return calendar;
}

Json::Value WeeklyCalendar::formClassData(QString name, QString day, QString time)
{
    Json::Value classData;

    classData["name"] = name.toStdString();
    classData["day"] = day.toStdString();
    classData["time"] = time.toStdString();

    return classData;
}

void WeeklyCalendar::appendClass(Json::Value newClass, QString username, QString role)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value wantedRoleData = dataHolder[role.toStdString()];

        for(int i = 0; i < wantedRoleData.size(); i++)
        {
            if(wantedRoleData[i]["username"] == username.toStdString())
            {
                Json::Value wantedUsernameClasses = wantedRoleData[i]["classes"];

                wantedUsernameClasses.append(newClass);

                Json::StyledWriter writer;

                ofstream jsonWriter(filePath.toStdString());

                dataHolder[role.toStdString()][i]["classes"] = wantedUsernameClasses;

                string serializedData = writer.write(dataHolder);

                jsonWriter << serializedData;

                jsonWriter.close();
            }
        }
    }
}

void WeeklyCalendar::deleteClass(Class Class, QString username, QString role)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value wantedRoleData = dataHolder[role.toStdString()];

        for(int i = 0; i < wantedRoleData.size(); i++)
        {
            if(wantedRoleData[i]["username"] == username.toStdString())
            {
                Json::Value wantedUsernameClasses = wantedRoleData[i]["classes"];

                Json::Value classesCopy;

                for(int j = 0; j < wantedUsernameClasses.size(); j++)
                {
                    if(wantedUsernameClasses[j]["name"] != lesson_enum_str[Class.getLesson()].toStdString())
                    {
                        classesCopy.append(wantedUsernameClasses[j]);
                    }
                }

                Json::StyledWriter writer;

                ofstream jsonWriter(filePath.toStdString());

                dataHolder[role.toStdString()][i]["classes"] = classesCopy;

                string serializedData = writer.write(dataHolder);

                jsonWriter << serializedData;

                jsonWriter.close();
            }
        }
    }

}
