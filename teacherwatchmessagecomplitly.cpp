#include "teacherwatchmessagecomplitly.h"
#include "teacherclassinfo.h"
#include "ui_teacherwatchmessagecomplitly.h"
#include "teachermessages.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teacherweeklyschedule.h"
#include <QMessageBox>

teacherWatchMessageComplitly::teacherWatchMessageComplitly(QWidget *parent) :
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
}

teacherWatchMessageComplitly::~teacherWatchMessageComplitly()
{
    delete ui;
}

void teacherWatchMessageComplitly::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile;
        tp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherWatchMessageComplitly::on_pushButton_8_clicked()
{
    teacherMessages* tm= new teacherMessages;
    tm->show();
    close();
}


void teacherWatchMessageComplitly::on_pushButton_10_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion;
        tsa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherWatchMessageComplitly::on_backToMenu_clicked()
{
    teacherMessages* tm= new teacherMessages;
    tm->show();
    close();
}


void teacherWatchMessageComplitly::on_pushButton_11_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule;
        tws->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherWatchMessageComplitly::on_pushButton_9_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassInfo* tci = new TeacherClassInfo;
        tci->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}

