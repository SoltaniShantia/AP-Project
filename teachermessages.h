#ifndef TEACHERMESSAGES_H
#define TEACHERMESSAGES_H

#include <QWidget>
#include <QGroupBox>
#include <memory>

#include"dist/json/json.h"
#include"teachermainmenu.h"
#include "Notification.h"

namespace Ui {
class teacherMessages;
}

using std::unique_ptr, std::make_unique;

class teacherMessages : public QWidget
{
    Q_OBJECT

public:
    explicit teacherMessages(TeacherMainMenu * member , QWidget *parent = nullptr);
    ~teacherMessages();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_msgBtn_clicked(QString title, QString description , QString senderUsername);

    void on_pushButton_5_clicked();

private:
    Ui::teacherMessages *ui;

    TeacherMainMenu * mainmenu;

    QList<QString>    unreadMessages;
    QList<QString>    unreadTitle;
    QList<QString>    unReadsender;
    QList<QString>    readMessages;
    QList<QString>    readTitle;
    QList<QString>    Readsender;

    unique_ptr<Notification> notification;

    void showMeassages();

    QGroupBox* createMessageBox(QString messageTitle, QString messageDescription, QString senderUsername , int id);

//    Json::Value dataHolder;
//    Json::Reader dataReader;
//    QString filePath = "../data_resources/notifications.json";
};

#endif // TEACHERMESSAGES_H
