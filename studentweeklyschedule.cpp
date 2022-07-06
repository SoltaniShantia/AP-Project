#include "studentweeklyschedule.h"
#include "ui_studentweeklyschedule.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include <QMessageBox>
#include "studentmainmenu.h"

studentWeeklySchedule::studentWeeklySchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentWeeklySchedule)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
}

studentWeeklySchedule::~studentWeeklySchedule()
{
    delete ui;
}

void studentWeeklySchedule::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile;
        sp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void studentWeeklySchedule::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentMessages* sm= new studentMessages;
        sm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void studentWeeklySchedule::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu;
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}

