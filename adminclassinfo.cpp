#include <QGridLayout>
#include<QString>
#include<fstream>
#include<iostream>
using namespace std ;

#include "adminclassinfo.h"
#include "ui_adminclassinfo.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "adminmainmenu.h"
#include "QMessageBox"
#include "adminaddclass.h"
#include "adminwatchstudent.h"
#include"dist/json/json.h"
#include"Auth.h"
#include"Filemanager.h"
using namespace std;



AdminClassInfo::AdminClassInfo(AdminMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminClassInfo)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;

    Json::Reader dataReader;
    Json::Value dataHolder ;
    ifstream ifs("../data_resources/teacher_lessons.json");
    if(dataReader.parse(ifs , dataHolder))
    {
        for (int i = 0 ; i<dataHolder.size();i++)
        {
            for(auto j : dataHolder[i]["lessons"])
            {
                ui->verticalLayout_2->addWidget(watchClass(QString::fromStdString(dataHolder[i]["teacher"].asString()) , QString::fromStdString(j.asString())));
            }
        }




    }
}

AdminClassInfo::~AdminClassInfo()
{
    delete ui;
}

QGroupBox *AdminClassInfo::watchClass(QString teacherUsername , QString lesson)
{
    int userIndex = Auth::findUser(teacherUsername);

    FileManager userFile;
    userFile.create();
    userFile.loadData();

    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

    Class thisClass(string_to_lesson(lesson),teacherUsername);

    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * className = new QLabel;
    className->setMaximumWidth(210);
    className->setMaximumHeight(20);
    className->setText(lesson);
    className->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * teacherName = new QLabel;
    teacherName->setMaximumWidth(210);
    teacherName->setMaximumHeight(20);
    teacherName->setText(parsedUser[2] + " " + parsedUser[3]);
    teacherName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(95);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText(QString:: fromStdString(to_string(thisClass.getStudentNum())));
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton* watchBtn = new QPushButton;
    QString Name;
    connect(watchBtn,&QPushButton::clicked,[this, thisClass] { goToClassInfo(thisClass);});
    watchBtn->setMaximumWidth(101);
    watchBtn->setMaximumHeight(26);
    watchBtn->setText("Watch More");
    watchBtn->setStyleSheet("background-color: transparent;color:rgb(178, 8, 55);");


    grid->addWidget(className,0,0);
    grid->addWidget(teacherName,0,1);
    grid->addWidget(studentNumber,0,2);
    grid->addWidget(watchBtn,0,3);

    gBox->setLayout(grid);
    return gBox;

}

void AdminClassInfo::goToClassInfo(Class classToShow)
{
    AdminWatchStudent* aws = new AdminWatchStudent(mainmenu, classToShow);
    aws->show();
    close();

}

void AdminClassInfo::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() , mainmenu);
        amm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void AdminClassInfo::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminProfile* ap= new AdminProfile(mainmenu);
        ap->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void AdminClassInfo::on_pushButton_2_clicked()
{

    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to messages","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminMessages* as = new adminMessages(mainmenu);
        as->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void AdminClassInfo::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add people","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminAddPeople* aap= new AdminAddPeople(mainmenu);
        aap->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }

}


void AdminClassInfo::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion;
        asa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }

}


void AdminClassInfo::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add class","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminAddClass* adc= new adminAddClass(mainmenu);
        adc->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }

}

