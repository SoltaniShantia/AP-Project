#include "teacherweeklyschedule.h"
#include "ui_teacherweeklyschedule.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermessages.h"
#include "teachermainmenu.h"
#include "TeacherWeeklyCalendar.h"

#include <QMessageBox>

teacherWeeklySchedule::teacherWeeklySchedule(TeacherMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherWeeklySchedule)
{
    ui->setupUi(this);
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_8->setStyleSheet("background-color: transparent");
    this->ui->pushButton_9->setStyleSheet("background-color: transparent");
    this->ui->pushButton_10->setStyleSheet("background-color: transparent");
    this->ui->pushButton_11->setStyleSheet("background-color: transparent");
    this->ui->pushButton_12->setStyleSheet("background-color: transparent");

    ui->refreshButton->setStyleSheet("border: none; outline: none; background-color: #36454F; color: white; border-radius: 3px;");

    this->mainmenu = member;

    this->weeklyCalendar.reset(new TeacherWeeklycalendar);

    this->loadSchedule();

    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->label_10->setText("Hi dear " + mainmenu->get_first_name());

}

teacherWeeklySchedule::~teacherWeeklySchedule()
{
    delete ui;
}

void teacherWeeklySchedule::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","Do you want to leave?");

    exit->setStandardButtons(QMessageBox::Yes);

    exit->addButton(QMessageBox::No);

    exit->setDefaultButton(QMessageBox::No);

    exit->show();

    if(exit->exec() == QMessageBox::Yes)
    {
        teacherProfile* tp= new teacherProfile(mainmenu);

        tp->show();

        exit->close();

        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else
    {
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void teacherWeeklySchedule::on_pushButton_8_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","Do you want to leave?");

    exit->setStandardButtons(QMessageBox::Yes);

    exit->addButton(QMessageBox::No);

    exit->setDefaultButton(QMessageBox::No);

    exit->show();

    if(exit->exec() == QMessageBox::Yes)
    {
        teacherMessages* tm= new teacherMessages(mainmenu);

        tm->show();

        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else
    {
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void teacherWeeklySchedule::on_pushButton_10_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");

    exit->setStandardButtons(QMessageBox::Yes);

    exit->addButton(QMessageBox::No);

    exit->setDefaultButton(QMessageBox::No);

    exit->show();

    if(exit->exec() == QMessageBox::Yes)
    {
        TeacherSendAssertion* tsa= new TeacherSendAssertion;

        tsa->show();

        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else
    {
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void teacherWeeklySchedule::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);

    exit->addButton(QMessageBox::No);

    exit->setDefaultButton(QMessageBox::No);

    exit->show();

    if(exit->exec() == QMessageBox::Yes)
    {
        TeacherMainMenu* smm = new TeacherMainMenu(mainmenu->get_first_name(), mainmenu->get_username(), mainmenu);

        smm->show();

        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else
    {
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void teacherWeeklySchedule::loadSchedule()
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





void teacherWeeklySchedule::on_refreshButton_clicked()
{
    this->loadSchedule();
}

