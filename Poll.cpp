#include "Poll.h"

#include <fstream>
#include <iostream>

using namespace std;

Poll::Poll()
{
    // these few line(to the if statement) checks wether file exists or not if it exists construcor won't init data
    ifstream ifs(filePath.toStdString());

    if(ifs)
    {
        cout << "Json File Found..." << endl;

        return;
    }

    Json::Value baseData;

    baseData["bp"] = Json::arrayValue;
    baseData["chemistry"] = Json::arrayValue;
    baseData["calculus"] = Json::arrayValue;
    baseData["discrete"] = Json::arrayValue;
    baseData["physics"] = Json::arrayValue;

    Json::StyledWriter writer;

    ofstream jsonWriter(filePath.toStdString());

    string serializedData = writer.write(baseData);

    jsonWriter << serializedData;

    jsonWriter.close();


    return;
}

void Poll::addScore(int score, QString studentUsername, QString lessonName, QString teacherUsername)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value pollStruct;

        pollStruct["student_username"] = studentUsername.toStdString();
        pollStruct["score"] = score;
        pollStruct["teacher_name"] = teacherUsername.toStdString();

        Json::Value wantedLesson = dataHolder[lessonName.toStdString()];

        wantedLesson.append(pollStruct);

        dataHolder[lessonName.toStdString()] = wantedLesson;

        Json::StyledWriter writer;

        ofstream jsonWriter(filePath.toStdString());

        string serializedData = writer.write(dataHolder);

        jsonWriter << serializedData;

        jsonWriter.close();
    }
}

float Poll::getScore(QString lessonName, QString teacherUsername)
{
    ifstream ifs(filePath.toStdString());
    if (dataReader.parse(ifs , dataHolder))
    {
        Json::Value wantedLesson = dataHolder[lessonName.toStdString()] ;
        int sum = 0;
        int count =0 ;
        for(int i = 0 ; i < wantedLesson.size() ; i++)
        {
            if (wantedLesson[i]["teacher_username"] == teacherUsername.toStdString() )
            {
                count++;
                sum += wantedLesson[i]["score"].asInt() ;
            }
        }
        return static_cast<float>(sum)/count;
    }
    return -1 ;
}


