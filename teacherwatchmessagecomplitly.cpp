#include <QMessageBox>
#include<QString>
#include<fstream>

#include<iostream>
using namespace std;

#include"dist/json/json.h"
#include "teacherwatchmessagecomplitly.h"
#include "ui_teacherwatchmessagecomplitly.h"
#include "teachermessages.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teacherweeklyschedule.h"
#include"Auth.h"
#include"Filemanager.h"


teacherWatchMessageComplitly::teacherWatchMessageComplitly(QString title , QString message, QString senderUsername , TeacherMainMenu * member, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherWatchMessageComplitly)
{
    ui->setupUi(this);
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_8->setStyleSheet("background-color: transparent");
    this->ui->pushButton_9->setStyleSheet("background-color: transparent");
    this->ui->pushButton_10->setStyleSheet("background-color: transparent");
    this->ui->pushButton_11->setStyleSheet("background-color: transparent");
    this->ui->pushButton_12->setStyleSheet("background-color: transparent");

    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->TitleLine->setEnabled(false);
    this->ui->SenderLine->setEnabled(false);
    this->ui->messageLine->setEnabled(false);

    this->mainmenu = member;
    this->ui->label_9->setText("Hi dear " + mainmenu->get_first_name());

//    this->ui->SenderLine->setText(sender);
    this->ui->TitleLine->setText(title);
    this->ui->messageLine->setText(message);


    int userIndex = Auth::findUser(senderUsername);
    FileManager userFile;
    userFile.create();
    userFile.loadData();

    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

    this->ui->SenderLine->setText(parsedUser[2] + " " + parsedUser[3]);


//    if(isread == false)
//    {
//        ifstream ifs(this->filePath.toStdString());
//        if(this->dataReader.parse(ifs , this->dataHolder))
//        {
//            Json::Value members;
//            for(auto i: this->dataHolder  )
//            {
//                if(QString::fromStdString(i["allowed_student"][0]["username"].asString()) != "#")
//                    members.append(i);
//                else
//                {
//                    if(QString::fromStdString(i["allowed_student"][0]["is_read"].asString()) == "true")
//                        members.append(i);
//                    else
//                    {
//                        Json::Value appended;
//                        appended["is_read"] = "true";
//                        appended["username"] = "#";
//                        Json::Value changedMember;
//                        changedMember["allowed_student"].append(appended);
//                        changedMember["description"] = i["description"];
//                        changedMember["sender"] = i["sender"];
//                        changedMember["title"] = i["title"];
//                        members.append(changedMember);
//                    }
//                }
//            }
//            this->dataHolder = members ;
//            ofstream ofs(this->filePath.toStdString());
//            Json::StyledWriter writer;
//            string finalPart = writer.write(this->dataHolder);
//            ofs << finalPart;
//            ofs.close();
//        }

//    }
}

teacherWatchMessageComplitly::~teacherWatchMessageComplitly()
{
    delete ui;
}

void teacherWatchMessageComplitly::on_pushButton_7_clicked()
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

void teacherWatchMessageComplitly::on_pushButton_8_clicked()
{
    teacherMessages* tm= new teacherMessages(mainmenu);
    tm->show();
    close();
}

void teacherWatchMessageComplitly::on_pushButton_10_clicked()
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

void teacherWatchMessageComplitly::on_backToMenu_clicked()
{
    teacherMessages* tm= new teacherMessages(mainmenu);
    tm->show();
    close();
}

void teacherWatchMessageComplitly::on_pushButton_11_clicked()
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

