#include "adminaddclass.h"
#include "ui_adminaddclass.h"
#include "adminmainmenu.h"
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "Class.h"
#include"teachermainmenu.h"
#include "Filemanager.h"
#include "TeacherWeeklyCalendar.h"

#include <QMessageBox>
#include <iostream>

adminAddClass::adminAddClass(AdminMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminAddClass)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_9->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;

    this->loadTeacherList();

    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());
}

adminAddClass::~adminAddClass()
{
    delete ui;
}

void adminAddClass::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() ,mainmenu);
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


void adminAddClass::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminProfile* ap= new AdminProfile(this->mainmenu);
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


void adminAddClass::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to messages","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminMessages* as = new adminMessages(this->mainmenu);
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


void adminAddClass::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add people","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminAddPeople* aap= new AdminAddPeople(this->mainmenu);
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


void adminAddClass::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion(this->mainmenu);
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


void adminAddClass::on_pushButton_5_clicked()
{

    QTime startingTime = ui->startingTime->time();

    QTime endingTime = ui->endingTime->time();

    QString strStartingTime = QString::number(startingTime.hour()) + ":" + QString::number(startingTime.minute());

    QString strEndingTime = QString::number(endingTime.hour()) + ":" + QString::number(endingTime.minute());

    qDebug() << startingTime;

    qDebug() << strStartingTime;

//    Class newClass (string_to_lesson(lesson_enum_str[this->lesson]), this->teacherusername);

//    newClass.setLocation(this->location);

//    newClass.setTime(this->time);

//    newClass.setDay(string_to_day(day_enum_str[this->day]));

//    TeacherMainMenu::addNewLessonFile(this->teacherusername , newClass);

//    QMessageBox* classAdded = new QMessageBox(QMessageBox::Icon::Information, "class Added", "Class with entered info created.", QMessageBox::Button::Ok);
//    classAdded->show();

}


void adminAddClass::on_comboBox_4_currentIndexChanged(int index)
{
    this->lesson = index;
}


void adminAddClass::on_comboBox_3_currentIndexChanged(int index)
{
    this->day = index;
}


void adminAddClass::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    this->location = arg1;
}


void adminAddClass::on_pushButton_6_clicked()
{
    qDebug() << this->teacherusername;

    qDebug() << this->location;

    qDebug() << this->startingTime;

    qDebug() << this->endingTime;


   Class newClass(string_to_lesson(lesson_enum_str[this->lesson]), this->teacherusername);

   newClass.setLocation(this->location);

   newClass.setTime(this->startingTime + " - " + this->endingTime);

   newClass.setDay(string_to_day(day_enum_str[this->day]));

   TeacherMainMenu::addNewLessonFile(this->teacherusername , newClass);

   TeacherWeeklycalendar twc;

   twc.addClass(this->teacherusername, newClass);

   QMessageBox* classAdded = new QMessageBox(QMessageBox::Icon::Information, "class Added", "Class with entered info created.", QMessageBox::Button::Ok);

   classAdded->show();

}

void adminAddClass::loadTeacherList()
{
    auto teacherComboList = ui->teacherCombo;

    FileManager userFile;

    userFile.create();

    userFile.loadData();

    for(auto& user : userFile.getData())
    {
        auto parsedUser = userFile.parse(user);

        auto userRole = parsedUser.at(parsedUser.size() - 1);

        if(userRole == "Teacher")
        {
            teacherComboList->addItem(parsedUser.at(0));
        }
    }

}

void adminAddClass::on_teacherCombo_currentTextChanged(const QString &arg1)
{
    this->teacherusername = arg1;
}


void adminAddClass::on_startingTime_userTimeChanged(const QTime &time)
{
    this->startingTime = QString::number(time.hour()) + ":" + QString::number(time.minute());
}


void adminAddClass::on_endingTime_userTimeChanged(const QTime &time)
{
    this->endingTime = QString::number(time.hour()) + ":" + QString::number(time.minute());
}

