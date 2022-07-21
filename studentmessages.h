#ifndef STUDENTMESSAGES_H
#define STUDENTMESSAGES_H

#include <QWidget>
#include <QGroupBox>
#include <memory>

#include"dist/json/json.h"
#include "Notification.h"
#include"studentmainmenu.h"

namespace Ui {
class studentMessages;
}

using std::unique_ptr, std::make_unique;


class studentMessages : public QWidget
{
    Q_OBJECT

public:
    explicit studentMessages(StudentMainMenu * memeber, QWidget *parent = nullptr);
    ~studentMessages();

private:
    QGroupBox* showMessages(int i);

private slots:
    void on_pushButton_clicked();

    void on_backToMenu_clicked();

    //void on_msgbtn1_clicked();

    void on_pushButton_3_clicked();

    void on_msgBtn_clicked(QString title, QString description , QString senderUsername);
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::studentMessages *ui;

    StudentMainMenu * mainmenu ;


    unique_ptr<Notification> notification;

    void showMeassages();

    QGroupBox *createMessageBox(QString messageTitle, QString messageDescription, QString senderUsername , int id);


};

#endif // STUDENTMESSAGES_H
