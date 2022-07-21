#include <QMessageBox>
#include<fstream>
#include<QString>

#include<iostream>
using namespace std;


#include "teachermessages.h"
#include "ui_teachermessages.h"
#include "teachersendassertion.h"
#include "teachermainmenu.h"
#include "teacherprofile.h"
#include "teacherwatchmessagecomplitly.h"
#include "teacherweeklyschedule.h"


teacherMessages::teacherMessages(TeacherMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherMessages),
    mainmenu(member)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");


    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    this->notification.reset(new Notification);

    this->showMeassages();

//    ifstream ifs(this->filePath.toStdString());
//    if(this->dataReader.parse(ifs , this->dataHolder))
//    {
//        for (auto i : this->dataHolder)
//        {
//            if(QString::fromStdString(i["allowed_users"].asString()) == "#")
//            {
//                if(i["allowed_users"][0]["is_read"] == false)
//                {
//                    this->unReadsender.push_back(QString::fromStdString(i["sender"].asString()));
//                    this->unreadMessages.push_back(QString::fromStdString(i["description"].asString()));
//                    this->unReadsender.push_back(QString::fromStdString(i["title"].asString()));
//                }
//                else if (i["allowed_users"][0]["is_read"] == true)
//                {
//                    this->Readsender.push_back(QString::fromStdString(i["sender"].asString()));
//                    this->readMessages.push_back(QString::fromStdString(i["description"].asString()));
//                    this->Readsender.push_back(QString::fromStdString(i["title"].asString()));

//                }
//                else
//                {
//                    exception e("\"is_read\" in file\"../data_resources/studentnotification\" doesen't contain acceptable parameters");
//                    emit mainmenu->exceptioOccured(e);
//                }
//            }
//        }
//        ifs.close();
//    }
//    else
//    {
//        exception e("coulden't open file \"../data_resources/studentnotification\"");
//        emit mainmenu->exceptioOccured(e);
//    }
}

teacherMessages::~teacherMessages()
{
    delete ui;
}

QGroupBox *teacherMessages::createMessageBox(QString messageTitle, QString messageDescription, QString senderUsername , int id)
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * msgTitle = new QLabel;
    msgTitle->setMaximumWidth(81);
    msgTitle->setMaximumHeight(20);
    msgTitle->setText(messageTitle);
    msgTitle->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * msg = new QLabel;
    msg->setMaximumWidth(421);
    msg->setMaximumHeight(20);
    msg->setText(messageDescription);
    msg->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton* watchBtn = new QPushButton;   

    connect(watchBtn,&QPushButton::clicked,[this, messageTitle, messageDescription , senderUsername] { on_msgBtn_clicked(messageTitle, messageDescription , senderUsername);});

    watchBtn->setMaximumWidth(101);
    watchBtn->setMaximumHeight(26);
    watchBtn->setText("More Details");
    watchBtn->setStyleSheet("background-color: transparent;color:rgb(178, 8, 55);");

    grid->addWidget(msgTitle,0,0);
    grid->addWidget(msg,0,1);
    grid->addWidget(watchBtn,0,2);

    gBox->setLayout(grid);
    return gBox;

}

void teacherMessages::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile(mainmenu);
        tp->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}

void teacherMessages::showMeassages()
{
    auto notifs = notification->getNotifs(mainmenu->get_username());

    for(auto notif : notifs)
    {
        this->ui->verticalLayout_2->addWidget(
            createMessageBox(notif["title"], notif["description"], notif["sender"] , notif["id"].toInt())
        );
    }    
}

void teacherMessages::on_msgBtn_clicked(QString title, QString description , QString senderUsername)
{
    teacherWatchMessageComplitly* twmc = new teacherWatchMessageComplitly(title, description, senderUsername , mainmenu);
    twmc->show();
    close();    
}

void teacherMessages::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion;
        tsa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void teacherMessages::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* smm = new TeacherMainMenu(mainmenu->get_first_name(), mainmenu->get_username() , mainmenu );
        smm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


//void teacherMessages::on_msgbtn1_clicked()
//{
//    bool isread;
//    QString sender = nullptr;
//    for(int i = 0 ; i < unreadTitle.size() ; i++)
//    {
//        if(unreadTitle[i] == this->ui->msgtitle1->text() && this->ui->msg1->text() == unreadMessages[i])
//        {
//            sender = unReadsender[i];
//            isread = false;
//            break;
//        }
//    }
//    if(sender == nullptr)
//    {
//        for(int i = 0 ; i < readTitle.size() ; i++)
//        {
//            if(readTitle[i] == this->ui->msgtitle1->text() && this->ui->msg1->text() == readMessages[i])
//            {
//                sender = Readsender[i];
//                isread = true;
//                break;
//            }

//        }
//    }

//    if(sender!=nullptr)
//    {
//        teacherWatchMessageComplitly* twmc = new teacherWatchMessageComplitly(this->ui->msgtitle1->text() , this->ui->msg1->text() , sender ,  isread , mainmenu);
//        twmc->show();
//        close();
//    }
//    else
//    {
//        exception e("coulden't find the message");
//        emit mainmenu->exceptioOccured(e);
//    }


//}


void teacherMessages::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule(mainmenu);
        tws->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}
