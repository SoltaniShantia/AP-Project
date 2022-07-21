#ifndef POLL_H
#define POLL_H

#include "dist/json/json.h"

#include <QString>

class Poll
{
private:
    QString filePath = "../data_resources/poll.json";
    Json::Reader dataReader;
    Json::Value dataHolder;

public:
    Poll();

    void addScore(int score, QString studentUsername, QString lessonName, QString teacherUsername);
    float getScore(QString lessonName , QString teacherUsername);


};

#endif // POLL_H
