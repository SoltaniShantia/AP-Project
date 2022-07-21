#include "studentenrolment.h"
#include "ui_studentenrolment.h"
#include "studentmainmenu.h"
#include "loginpage.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentweeklyschedule.h"
#include "studentteachersurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "QCheckBox"
#include "Auth.h"
#include "Filemanager.h"
#include "StudentWeeklyCalendar.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <iostream>
#include <fstream>

using namespace std;

StudentEnrolment::StudentEnrolment(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentEnrolment)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
//    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    Json::Value TdataHolder;
    Json::Reader TdataReader;
    ifstream ifs("../data_resources/teacher_lessons.json");

    if(TdataReader.parse(ifs , TdataHolder))
    {
        for(auto teacher : TdataHolder)
        {
            QString teacherUsr = QString::fromStdString( teacher["teacher"].asString());

            for(auto &lesson : teacher["lessons"])
            {
                enum lesson this_lesson = string_to_lesson(QString::fromStdString(lesson.asString()));
                Class classToShow(this_lesson, teacherUsr);

                ui->verticalLayout_2->addWidget(showLessons(classToShow));
//                this->mainmenu->registry(classToShow);
            }
        }
    }
    ifs.close();
}

StudentEnrolment::~StudentEnrolment()
{
    delete ui;
}

void StudentEnrolment::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile(mainmenu);
        sp->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void StudentEnrolment::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentMessages* sm= new studentMessages(mainmenu);
        sm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }


}


void StudentEnrolment::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentWeeklySchedule* swc = new studentWeeklySchedule(mainmenu);
        swc->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentEnrolment::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to view scores","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTerms* st = new StudentTerms(mainmenu);
        st->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentEnrolment::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher survey","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTeacherSurvey* sts = new StudentTeacherSurvey(mainmenu);
        sts->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentEnrolment::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu->get_first_name() , mainmenu->get_username() , mainmenu);
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


QGroupBox *StudentEnrolment::showLessons(Class classToShow)
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * CLassName = new QLabel;
    CLassName->setMaximumWidth(95);
    CLassName->setMaximumHeight(20);
    CLassName->setText(lesson_enum_str[classToShow.getLesson()]);
    CLassName->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * teacherName = new QLabel;
    teacherName->setMaximumWidth(95);
    teacherName->setMaximumHeight(20);

    int userIndex = Auth::findUser(classToShow.getTeacher());
    FileManager userFile;
    userFile.create();
    userFile.loadData();
    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

    teacherName->setText(parsedUser[2] + ' ' + parsedUser[3]);
    teacherName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * Time = new QLabel;
    Time->setMaximumWidth(95);
    Time->setMaximumHeight(20);
    Time->setText(classToShow.getTime());
    Time->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QCheckBox * selection = new QCheckBox();
    QString nameOfTerm;
    selection->setMaximumWidth(40);
    selection->setMaximumHeight(20);
    connect(selection, &QCheckBox::stateChanged, [this, classToShow, selection] { registeryStatus(classToShow, selection); } );
    //connect(showScore,&QPushButton::clicked,[this, nameOfTerm] { goToScores(nameOfTerm);});


    grid->addWidget(CLassName,0,0);
    grid->addWidget(teacherName,0,1);
    grid->addWidget(Time,0,2);
    grid->addWidget(selection,0,3);

    gBox->setLayout(grid);
    return gBox;
}

void StudentEnrolment::registeryStatus(Class classToShow, QCheckBox *selection)
{
    StudentWeeklyCalendar swc;

    mainmenu->finalizeRegistering();

    if (selection->isChecked()){

        swc.addClass(mainmenu->get_username(), classToShow);

        this->mainmenu->registry(classToShow);

        QMessageBox* registred = new QMessageBox(QMessageBox::Icon::Information, "registred", "The lesson has been added successfully!", QMessageBox::Button::Ok);

        registred->show();

        connect(registred , &QMessageBox::buttonClicked , registred , &QMessageBox::deleteLater);
    }

    else{

        swc.removeClass(mainmenu->get_username(), classToShow);

        this->mainmenu->unregistery(classToShow);

        QMessageBox* unregistred = new QMessageBox(QMessageBox::Icon::Information, "unregistred", "The lesson has been deleted successfully!", QMessageBox::Button::Ok);

        unregistred->show();

        connect(unregistred , &QMessageBox::buttonClicked , unregistred , &QMessageBox::deleteLater);
    }
}


