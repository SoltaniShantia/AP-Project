#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QVector>
#include <QMultiMap>
#include <iterator>
#include<fstream>
#include<iostream>
using namespace std;



#include "teachermainmenu.h"
#include "teachersendassertion.h"
#include "ui_teachermainmenu.h"
#include "loginpage.h"
#include "teacherprofile.h"
//#include "ui_Teacher.h"
#include "Auth.h"
#include "Filemanager.h"
#include "User.h"
#include"Notification.h"
#include "teachermessages.h"
#include"dist/json/json.h"
#include"teacherclassinfo.h"
#include "teacherclasssetscore.h"
#include "teacherweeklyschedule.h"

TeacherMainMenu::TeacherMainMenu(QString firstname , QString username , TeacherMainMenu * member, QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::TeacherMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->label_13->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");


    this->mainmenu = member;
    if(member!=nullptr)
    {
        this->set_username(mainmenu->get_username());
        this->set_password(mainmenu->get_password());
        this->set_last_name(mainmenu->get_last_name());
        this->set_role(mainmenu->get_role());
        this->set_national_code(mainmenu->get_national_code());
        this->set_phone_number(mainmenu->get_phone_number());
    }

    this->set_username(username);

    this->set_first_name(firstname);
    this->ui->label_2->setText("Hi dear " + this->get_first_name());

    //working with file fot teacher class
    initFile();
}

TeacherMainMenu::~TeacherMainMenu()
{
    delete ui;
}

void TeacherMainMenu::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}

void TeacherMainMenu::on_pushButton_clicked()
{
    teacherProfile* tp = new teacherProfile(this);
    tp->show();
    close();
}

void TeacherMainMenu::  deleteStudent(QString studentname , Class Class)

{
//    can be checked in Class.cpp:
//    int index = Auth::validStudent(studentname , Class.getLesson());
    if(Class.studentIsValid(studentname))
    {
        Class.deleteStudent(studentname);

        Json::Value SdataHolder;
        Json::Reader SdataReader;
        ifstream ifs("../data_resources/student_term.json");

        if(SdataReader.parse(ifs, SdataHolder))
        {
            for(int i = 0; i < SdataHolder.size(); i++)
            {
                if(studentname.toStdString() == SdataHolder[i]["username"].asString())
                {
                    int Term = SdataHolder[i]["count_of_terms"].asInt()-1;

                    Json::Value classesCopy = SdataHolder[i]["terms"][Term]["lessons"];

                    Json::Value wantedClasses;

                    for(int j = 0; j < classesCopy.size(); j++)
                    {
                        if(classesCopy[j]["lesson"].asString() != lesson_enum_str[Class.getLesson()].toStdString() )
                            wantedClasses.append(classesCopy[j]);
                    }

                    SdataHolder[i]["terms"][Term]["lessons"] = wantedClasses;

                    ofstream ofs("../data_resources/student_term.json");

                    Json::StyledWriter writer;

                    string serializedData = writer.write(SdataHolder);

                    ofs << serializedData;

                    ofs.close();

                    return;
                }
            }
        }
//    remove class from student's classes


//    if (newPass != confirmNewPass)
//    {
//        QMessageBox * confirmPassDoesntMatch = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
//        confirmPassDoesntMatch->show();
//        connect(confirmPassDoesntMatch , &QMessageBox::buttonClicked , confirmPassDoesntMatch, &QMessageBox::deleteLater);
//        return;
//    }


    QMessageBox * studentdeleted = new QMessageBox(QMessageBox::Icon::Information, "Student removed", "the student was removed succesfuly", QMessageBox::Button::Ok);
//    studentdeleted->setParent(this);

    studentdeleted->show();

    QObject::connect(studentdeleted , &QMessageBox::buttonClicked , studentdeleted , &QMessageBox::deleteLater);

//    LoginPage* lg = new LoginPage;

//    connect(studentdeleted, &QMessageBox::buttonClicked, lg, &LoginPage::show);

    //    connect(studentdeleted, &QMessageBox::buttonClicked, this, &EntereNewPass::close);
    }
    else{
//        student not valid
    }
}

void TeacherMainMenu::setScores(Class Class)
{



//    Class.setScore(studentname, score);

}


void TeacherMainMenu::sendingNotification(QString title , QString message , Class Class)
{
    QList <QString> list = Class.getList().keys();

    Notification member;
    QList<QMap<QString , QString>> studentUsernameList ;

    for (int i = 0 ;  i < list.size() ; i++)
    {
        QMap<QString , QString> member ;
        member["username"] = list[i];
        member["is_read"] = "false";
        studentUsernameList.push_back(member)  ;
    }
    member.addNotif(title , message , this->get_username() , studentUsernameList ) ;
}

void TeacherMainMenu::addNewTeacherToFile(QList<QString> lessons)
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        Json::Value teacherInformation ;
        teacherInformation["teacher"] = this->get_username().toStdString();
        for(auto &i : lessons)
        {
            teacherInformation["lessons"].append(i.toStdString());
        }
        this->dataHolder.append(teacherInformation);


        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << this->dataHolder;
        ofs.close();
        return;
    }
    exception exceptionReason("couldn't open file \"../data_resources/teacher_lessons.json\"");
    emit exceptioOccured(exceptionReason);
}

void TeacherMainMenu::addNewTeacherToFile(QString teacherUsername)
{
    Json::Value dataHolder;
    Json::Reader dataReader;
    ifstream ifs("../data_resources/teacher_lessons.json");
    if(dataReader.parse(ifs , dataHolder))
    {
        Json::Value teacherInformation ;
        teacherInformation["teacher"] = teacherUsername.toStdString();
        teacherInformation["lessons"] = Json::arrayValue;
        dataHolder.append(teacherInformation);
        ofstream ofs("../data_resources/teacher_lessons.json");
        Json::StyledWriter writer;
        string finalPart = writer.write(dataHolder);
        ofs << dataHolder;
        ofs.close();
        return;
    }
}

void TeacherMainMenu::addNewLessonFile(Class new_class)
{
    this->classes.push_back(new_class);

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto &members : this->dataHolder)
        {
            if(QString::fromStdString(members["teacher"].asString()) == this->get_username())
            {
                members["lessons"].append(lesson_enum_str[new_class.getLesson()].toStdString());
                break;
            }
        }
        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer ;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
    }
    exception exceptionReason("couldn't open file \"../data_resources/teacher_lessons.json\"");
    emit exceptioOccured(exceptionReason);
}

void TeacherMainMenu::addNewLessonFile(QString username, Class new_class)
{
    Json::Value dataHolder;
    Json::Reader dataReader;

    ifstream ifs("../data_resources/teacher_lessons.json");
    if(dataReader.parse(ifs , dataHolder))
    {
        for(auto &members : dataHolder)
        {
            if(QString::fromStdString(members["teacher"].asString()) == username)
            {
                members["lessons"].append(lesson_enum_str[new_class.getLesson()].toStdString());
                break;
            }
        }
        ofstream ofs("../data_resources/teacher_lessons.json");
        Json::StyledWriter writer ;
        string finalPart = writer.write(dataHolder);
        ofs << finalPart;
        ofs.close();
    }
}

void TeacherMainMenu::removeLessonFile(Class lesson) //delete all lessons? delete all class json files?
{
    for(auto i=0; i<classes.size(); i++){

        if(classes[i].getLesson()==lesson.getLesson()){
            this->classes.removeAt(i);
            break;}
    }

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        Json::Value undeletedLessons;
        for(auto &members : this->dataHolder)
        {
            if(QString::fromStdString(members["teacher"].asString()) == this->get_username() )
            {
                for(auto &ls : members["lessons"])
                {
                    if(QString::fromStdString(ls.asString()) != lesson_enum_str[lesson.getLesson() ])
                        undeletedLessons.append(ls);
                }
                members["lessons"] = undeletedLessons;
                break;
            }
            ofstream ofs(this->filePath.toStdString());
            Json::StyledWriter writer ;
            string finalPart = writer.write(this->dataHolder);
            ofs << finalPart;
            ofs.close();
        }
    }
    exception exceptionReason("couldn't open file \"../data_resources/teacher_lessons.json\"");
    emit exceptioOccured(exceptionReason);
}

int TeacherMainMenu::teacherIsValidFile()
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(int teacherIndex = 0 ; teacherIndex < this->dataHolder.size() ; teacherIndex ++)
        {
            if(QString::fromStdString(this->dataHolder[teacherIndex]["teacher"].asString()) == this->get_username())
                return teacherIndex;
        }
        return -1 ;
    }
    exception exceptionReason("couldn't open file \"../data_resources/teacher_lessons.json\"");
    emit exceptioOccured(exceptionReason);
    return -1;
}

int TeacherMainMenu::teacherIsValidFile(QString teacherUsername)
{
    Json::Value dataHolder;
    Json::Reader dataReader;
    ifstream ifs("../data_resources/teacher_lessons.json");
    if(dataReader.parse(ifs , dataHolder))
    {
        for(int teacherIndex = 0 ; teacherIndex < dataHolder.size() ; teacherIndex ++)
        {
            if(QString::fromStdString(dataHolder[teacherIndex]["teacher"].asString()) == teacherUsername)
                return teacherIndex;
        }
        return -1 ;
    }
    return -1;
}

bool TeacherMainMenu::lessonIsValid(QString lesson)
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto i : this->dataHolder)
        {
            if(QString::fromStdString(i["teacher"].asString()) == this->get_username())
            {
                for (auto j : i["lessons"])
                {
                    if (QString::fromStdString(j.asString()) == lesson)
                        return true ;
                }
                return false;
            }
        }
        return false ;
    }
    exception exceptionReason("couldn't open file \"../data_resources/teacher_lessons.json\"");
    emit exceptioOccured(exceptionReason);
    return false;
}

Class TeacherMainMenu::getLesson(lesson lesson)
{
    for(int i=0; i<classes.size(); i++){
        if(classes[i].getLesson()==lesson){
            return this->classes[i];
        }
    }

}

QString TeacherMainMenu::lessonNameCheck(QString sentName)
{
    if (sentName.toLower() == "physics")
        return "PHYSICS";
    else if (sentName.toLower() == "chemistry")
        return "CHEMISTRY";
    else if (sentName.toLower() == "calculus")
        return "CALCULUS";
    else if (sentName.toLower() == "basic programming" || sentName.toLower() == "bp")
        return "BP";
    else if (sentName.toLower() == "discrete")
        return "DISCRETE";
    else
    {
        throw std::exception ("The name you have entered is not valid\nPlease enter a valid lesson name.The cceptable names for lessons are :\nphysics\ncalculus\ndiscrete\nbsic programming\nchemistry");
    }

}

QList<Class> TeacherMainMenu::getClasses()
{
    return this->classes;
}

void TeacherMainMenu::cleantecher_lessons()
{
    string path = "../data_resources/teacher_lessons.json";

    ifstream ifs(path);

    Json::Value dataHolder;

    Json::Reader dataReader;

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            dataHolder[i]["lessons"] = Json::arrayValue;
        }

        ofstream ofs(path);

        Json::StyledWriter writer;

        string serializedData = writer.write(dataHolder);

        ofs << serializedData;

        ofs.close();
    }
}


void TeacherMainMenu::on_pushButton_3_clicked()
{
    TeacherClassInfo* tm = new TeacherClassInfo(this);

    tm->show();

    close();
}


void TeacherMainMenu::on_pushButton_6_clicked()
{
    TeacherClassSetScore* tcss = new TeacherClassSetScore(this);
    tcss->show();
    close();
}


void TeacherMainMenu::on_pushButton_4_clicked()
{
    TeacherSendAssertion* tsa = new TeacherSendAssertion(this);
    tsa->show();
    close();
}

void TeacherMainMenu::initFile()
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto teacher : this->dataHolder)
        {
            if(QString::fromStdString(teacher["teacher"].asString()) == this->get_username())
            {
                for(auto &lesson : teacher["lessons"])
                {
                    Class new_class(string_to_lesson( QString::fromStdString( lesson.asString())), this->get_username());
                    this->classes.push_back(new_class);
                }
                return;
            }
        }
        return;
    }


    ofstream ofs(filePath.toStdString());
    Json::StyledWriter writer;
//    this->dataHolder[0]["teacher"] = this->get_username().toStdString();
//    this->dataHolder[0]["lessons"] = Json::arrayValue;
    Json::Value baseData;

    Json::Value baseTeacher;

    baseTeacher["teacher"] = get_username().toStdString();
    baseTeacher["lessons"] =  Json::arrayValue;
    baseData.append(baseTeacher);

    string serializedData = writer.write(baseData);
    string finalPart = writer.write(baseData);
    ofs << finalPart;
    ofs.close();
    return;
}


void TeacherMainMenu::on_pushButton_2_clicked()
{
    teacherMessages* tm = new teacherMessages(this);

    close();

    tm->show();
}


void TeacherMainMenu::on_pushButton_5_clicked()
{
    teacherWeeklySchedule* tws = new teacherWeeklySchedule(this);
    tws->show();
    close();
}

