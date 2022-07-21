#include "studentweeklyschedule.h"
#include "ui_studentweeklyschedule.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentmainmenu.h"
#include "studentteachersurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "studentenrolment.h"
#include "StudentWeeklyCalendar.h"

#include <QMessageBox>

studentWeeklySchedule::studentWeeklySchedule(StudentMainMenu * member , QWidget *parent) :
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

    this->mainmenu = member;

    ui->refreshButton->setStyleSheet("border: none; outline: none; background-color: #36454F; color: white; border-radius: 3px;");

    this->weeklyCalendar.reset(new StudentWeeklyCalendar);

    this->loadSchedule();

    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

}

studentWeeklySchedule::~studentWeeklySchedule()
{
    delete ui;
}

void studentWeeklySchedule::on_pushButton_clicked()
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


void studentWeeklySchedule::on_pushButton_2_clicked()
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


void studentWeeklySchedule::on_backToMenu_clicked()
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


void studentWeeklySchedule::on_pushButton_7_clicked()
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


void studentWeeklySchedule::on_pushButton_6_clicked()
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


void studentWeeklySchedule::on_pushButton_4_clicked()
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


void studentWeeklySchedule::loadSchedule()
{
    weeklyCalendar->loadCalendar(mainmenu->get_username());

    weeklyCalendar->getCalendarDayByDay();

    auto dayByDayCalendar = weeklyCalendar->getSeperatedCalendar();

    if(weeklyCalendar->getCalendar().empty())
    {
        QMessageBox* emptyCalendar = new QMessageBox(QMessageBox::Warning,"Empty Schedule","No schedule found for you.");

        emptyCalendar->show();

        connect(emptyCalendar, &QMessageBox::buttonClicked, emptyCalendar, &QMessageBox::deleteLater);

        return;
    }

    for(int i = 0; i < dayByDayCalendar.size(); i++)
    {
        if(dayByDayCalendar.empty())
        {
            continue;
        }

        for(int j = 0; j < dayByDayCalendar.at(i).size(); j++)
        {
            QString wantedDayCellName = 'r' + QString::number(i) + 'c' + QString::number(j);

            auto wantedDay = this->findChild<QLabel *>(wantedDayCellName);

            auto currentDay = dayByDayCalendar.at(i).at(j);

            wantedDay->setText(currentDay["name"] + "\n" + currentDay["day"] + " - " + currentDay["time"]);

            wantedDay->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

            wantedDay->setStyleSheet("text-align: center; font-size: 7px; min-width: fit-content;");
        }
    }
}

void studentWeeklySchedule::on_refreshButton_clicked()
{
    this->loadSchedule();
}

