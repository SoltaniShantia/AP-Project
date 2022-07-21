#ifndef NOTIFICATION_H
#define NOTIFICATION_H



#include"dist/json/json.h"
#include<QString>
#include<QList>
#include<QMap>


class Notification
{
public:
    Notification();

    void addNotif(QString title , QString description , QString sender , QList<QMap<QString , QString>> allowedUsers);

    QList<QMap<QString , QString>> getNotifs(QString username);

    // if type = * it should be should to every one if type = S should show to students if type = T should show to teachers
    void addNotif(QString title, QString description, QString sender, QString type = "*");

private:
    Json::Reader dataReader;
    Json::Value dataHolder ;
    QString filePath = "../data_resources/notifications.json";

    int lastIndex;
};

#endif // NOTIFICATION_H
