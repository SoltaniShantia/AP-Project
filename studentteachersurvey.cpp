#include "studentteachersurvey.h"
#include "ui_studentteachersurvey.h"

#include "studentmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentweeklyschedule.h"
#include <QGridLayout>
#include <QLabel>
#include "studentwatchsurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "studentenrolment.h"
#include"Auth.h"
#include"Filemanager.h"

StudentTeacherSurvey::StudentTeacherSurvey(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentTeacherSurvey)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());





    QList<QMap<QString , QString>> lessons = mainmenu->getClasses(mainmenu->getTerm()-1);

    for (int i = 0 ; i<lessons.size();i++){
        ui->verticalLayout_2->addWidget(showTeachers(lessons[i]["teacher"] , lessons[i]["lesson"]));

    }
}

StudentTeacherSurvey::~StudentTeacherSurvey()
{
    delete ui;
}

void StudentTeacherSurvey::on_surveyBtn_clicked(QString nameOfClassing , QString teacherUsername , QString lesson)
{
    StudentWatchSurvey* sws = new StudentWatchSurvey(teacherUsername , lesson , mainmenu);
    sws->show();
    close();
}

QGroupBox *StudentTeacherSurvey::showTeachers(QString teacherUsername , QString lesson)
{

    int userIndex = Auth::findUser(teacherUsername);
    FileManager userFile;
    userFile.create();
    userFile.loadData();
    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));



    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * Name = new QLabel;
    Name->setMaximumWidth(81);
    Name->setMaximumHeight(20);
    Name->setText(parsedUser[2]);
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(81);
    lastName->setMaximumHeight(20);
    lastName->setText(parsedUser[3]);
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * ClassName = new QLabel;
    QString nameOfClass;
    ClassName->setMaximumWidth(81);
    ClassName->setMaximumHeight(20);
    ClassName->setText(lesson);
    ClassName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton * survey = new QPushButton;
    survey->setMaximumWidth(81);
    survey->setMaximumHeight(20);
    survey->setText("Watch Survey");
    survey->setStyleSheet("font:Montesrat 9px; color: rgb(178, 8, 55);background-color: transparent");
    connect(survey,&QPushButton::clicked,[this, nameOfClass , teacherUsername , lesson] { on_surveyBtn_clicked(nameOfClass , teacherUsername , lesson);});


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(ClassName,0,2);
    grid->addWidget(survey,0,3);

    gBox->setLayout(grid);
    return gBox;

}

void StudentTeacherSurvey::on_pushButton_clicked()
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


void StudentTeacherSurvey::on_pushButton_2_clicked()
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


void StudentTeacherSurvey::on_pushButton_3_clicked()
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




void StudentTeacherSurvey::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu->get_first_name(), mainmenu->get_username() , mainmenu);
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


void StudentTeacherSurvey::on_pushButton_6_clicked()
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


void StudentTeacherSurvey::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to enrolment","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentEnrolment* se = new StudentEnrolment(mainmenu);
        se->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}

