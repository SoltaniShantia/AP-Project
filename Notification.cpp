#include "Notification.h"
#include "Auth.h"

#include<fstream>
#include<iostream>
#include<QMessageBox>
#include<QObject>
#include<QAbstractButton>

using namespace std;

Notification::Notification()
{
    ifstream ifs(filePath.toStdString());
    if(dataReader.parse(ifs , dataHolder))
    {
        lastIndex = dataHolder[dataHolder.size() - 1]["id"].asInt();

        return ;
    }

    dataHolder = Json::arrayValue;

    ofstream ofs(filePath.toStdString());
    Json::StyledWriter writer;
    string finalPart = writer.write(dataHolder);
    ofs << finalPart;
    ofs.close();
}

void Notification::addNotif(QString title , QString description , QString sender , QList<QMap<QString , QString>> allowedUsers)
{
    ifstream ifs(filePath.toStdString());
    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value newAlert;
        newAlert["title"] = title.toStdString();
        newAlert["description"] = description.toStdString() ;
        newAlert["sender"] = sender.toStdString() ;

        Json::Value jsonAllowedStudents;
        for(auto &student : allowedUsers)
        {
            Json::Value jsonStudent ;
            jsonStudent["username"] = student["username"].toStdString();
            jsonStudent["is_read"] = student["is_read"].toStdString();
            jsonAllowedStudents.append(jsonStudent);
        }
        newAlert["allowed_users"] = jsonAllowedStudents;
        // first increment then assign it
        newAlert["id"] = ++lastIndex;
        dataHolder.append(newAlert);

        Json::StyledWriter writer ;
        ofstream ofwriter(filePath.toStdString());
        string finalPart = writer.write(dataHolder);
        ofwriter << finalPart;
        ofwriter.close();


        QMessageBox * done = new QMessageBox(QMessageBox::Icon::Information , "Sending assertion" , "The assertion was sent succesfuly" , QMessageBox::Button::Ok);
        done->show();
        QObject::connect(done , &QMessageBox::buttonClicked , done , &QMessageBox::deleteLater );
    }
    return ;
}

QList<QMap<QString, QString>> Notification::getNotifs(QString username)
{
    ifstream ifs(filePath.toStdString());
    QList<QMap<QString , QString>> relatedAlerts;

    if(dataReader.parse(ifs , dataHolder))
    {
        Json::Value wholeFile ;
        for(int i = 0 ; i < dataHolder.size() ; i++)
        {
            if(dataHolder[i]["allowed_users"].isArray())
            {
                for(int j = 0 ; j < dataHolder[i]["allowed_users"].size() ; j++ )
                {
                    if (dataHolder[i]["allowed_users"][j].asString() == username.toStdString())
                    {
                        QMap<QString , QString> relatedMessage;

                        relatedMessage.insert(
                            "title",
                            QString::fromStdString(dataHolder[i]["title"].asString())
                            );

                        relatedMessage.insert(
                            "description",
                            QString::fromStdString(dataHolder[i]["description"].asString())
                            );

                        relatedMessage.insert(
                            "sender",
                            QString::fromStdString(dataHolder[i]["sender"].asString())
                            );


                        relatedMessage.insert(
                            "id",
                            QString::fromStdString(dataHolder[i]["id"].asString())
                            );

                        relatedAlerts.push_back(relatedMessage);
                    }
                }

                continue;
            }

            if(dataHolder[i]["allowed_users"].asString() == "*")
            {
                QMap<QString , QString> relatedMessage;

                relatedMessage.insert(
                    "title",
                    QString::fromStdString(dataHolder[i]["title"].asString())
                    );

                relatedMessage.insert(
                    "description",
                    QString::fromStdString(dataHolder[i]["description"].asString())
                    );

                relatedMessage.insert(
                    "sender",
                    QString::fromStdString(dataHolder[i]["sender"].asString())
                    );


                relatedMessage.insert(
                    "id",
                    QString::fromStdString(dataHolder[i]["id"].asString())
                    );

                relatedAlerts.push_back(relatedMessage);

                continue;
            }

            QString userRole = Auth::getUserRole(username);

            if(userRole == "Teacher" && dataHolder[i]["allowed_users"].asString() == "T")
            {
                QMap<QString , QString> relatedMessage;

                relatedMessage.insert(
                    "title",
                    QString::fromStdString(dataHolder[i]["title"].asString())
                    );

                relatedMessage.insert(
                    "description",
                    QString::fromStdString(dataHolder[i]["description"].asString())
                    );

                relatedMessage.insert(
                    "sender",
                    QString::fromStdString(dataHolder[i]["sender"].asString())
                    );


                relatedMessage.insert(
                    "id",
                    QString::fromStdString(dataHolder[i]["id"].asString())
                    );

                relatedAlerts.push_back(relatedMessage);

                continue;
            }

            if(userRole == "Student" && dataHolder[i]["allowed_users"].asString() == "S")
            {
                QMap<QString , QString> relatedMessage;

                relatedMessage.insert(
                    "title",
                    QString::fromStdString(dataHolder[i]["title"].asString())
                    );

                relatedMessage.insert(
                    "description",
                    QString::fromStdString(dataHolder[i]["description"].asString())
                    );

                relatedMessage.insert(
                    "sender",
                    QString::fromStdString(dataHolder[i]["sender"].asString())
                    );


                relatedMessage.insert(
                    "id",
                    QString::fromStdString(dataHolder[i]["id"].asString())
                    );

                relatedAlerts.push_back(relatedMessage);

                continue;
            }
        }

        ifs.close();

        return relatedAlerts;
    }

    throw exception("Couldn't Open Notifications File.");
}

void Notification::addNotif(QString title, QString description, QString sender, QString type)
{
    ifstream ifs(filePath.toStdString());
    if(dataReader.parse(ifs , dataHolder))
    {

        Json::Value newAlert ;
        newAlert["title"] = title.toStdString();
        newAlert["description"] = description.toStdString() ;
        newAlert["sender"] = sender.toStdString() ;
        newAlert["allowed_users"] = type.toStdString();

        dataHolder.append(newAlert);

        Json::StyledWriter writer ;
        ofstream ofwriter(filePath.toStdString());
        string finalPart = writer.write(dataHolder);
        ofwriter << finalPart;
        ofwriter.close();


        QMessageBox * done = new QMessageBox(QMessageBox::Icon::Information , "Sending assertion" , "The assertion was sent succesfuly" , QMessageBox::Button::Ok);
        done->show();
        QObject::connect(done , &QMessageBox::buttonClicked , done , &QMessageBox::deleteLater );
    }
    return ;
}
