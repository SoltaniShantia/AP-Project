#include "teacherwatchstudent.h"
#include "ui_teacherwatchstudent.h"
#include "teacherclassinfo.h"
#include "teachermainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermessages.h"
#include "teacherweeklyschedule.h"
TeacherWatchStudent::TeacherWatchStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherWatchStudent)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(students());

    }
}

TeacherWatchStudent::~TeacherWatchStudent()
{
    delete ui;
}

void TeacherWatchStudent::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
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


void TeacherWatchStudent::on_pushButton_5_clicked()
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


void TeacherWatchStudent::on_pushButton_4_clicked()
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


void TeacherWatchStudent::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
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


void TeacherWatchStudent::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherMessages* tm= new teacherMessages;
        tm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherWatchStudent::on_pushButton_clicked()
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

QGroupBox *TeacherWatchStudent::students()
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * Name = new QLabel;
    Name->setMaximumWidth(81);
    Name->setMaximumHeight(20);
    Name->setText("Class Name");
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(81);
    lastName->setMaximumHeight(20);
    lastName->setText("Teacher Name");
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(81);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText("Student Number");
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QLabel * field = new QLabel;
    field->setMaximumWidth(81);
    field->setMaximumHeight(20);
    field->setText("Field");
    field->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(studentNumber,0,2);
    grid->addWidget(field,0,3);

    gBox->setLayout(grid);
    return gBox;
}

