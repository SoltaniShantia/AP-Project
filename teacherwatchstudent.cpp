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
#include "Auth.h"
#include "Filemanager.h"
#include "QString"

using namespace std;

TeacherWatchStudent::TeacherWatchStudent(TeacherMainMenu * member ,Class thisClass , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherWatchStudent)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");

    this->mainmenu = member ;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    this->ui->teacherName->setText(mainmenu->get_first_name()+ " " + mainmenu->get_last_name());
    this->ui->NumberOfStudent->setText(QString::fromStdString(to_string(thisClass.getStudentNum())));
    this->ui->ClassName->setText(lesson_enum_str[thisClass.getLesson()]);

    QList<QString> usernameList = thisClass.getList().keys();
    for (int i = 0 ; i<thisClass.getStudentNum();i++){

        int userIndex = Auth::findUser(usernameList[i]);

        FileManager userFile;
        userFile.create();
        userFile.loadData();

        QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

        ui->verticalLayout_2->addWidget(students(parsedUser[2],parsedUser[3],usernameList[i], thisClass));

    }
}

TeacherWatchStudent::~TeacherWatchStudent()
{
    delete ui;
}

void TeacherWatchStudent::on_backToMenu_clicked()
{

    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassInfo* tci = new TeacherClassInfo(mainmenu);
        tci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherWatchStudent::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule(mainmenu);
        tws->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }


}


void TeacherWatchStudent::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion;
        tsa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void TeacherWatchStudent::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassInfo* tci = new TeacherClassInfo(mainmenu);
        tci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherWatchStudent::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherMessages* tm= new teacherMessages(mainmenu);
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
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile(mainmenu);
        tp->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


QGroupBox *TeacherWatchStudent::students(QString firstname,QString lastname,QString studentusername, Class thisClass)
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
    Name->setText(firstname);
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(81);
    lastName->setMaximumHeight(20);
    lastName->setText(lastname);
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(81);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText(studentusername);
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QPushButton* deleteStudent = new QPushButton;
    deleteStudent->setMaximumWidth(81);
    deleteStudent->setMaximumHeight(20);
    deleteStudent->setText("remove student");

    connect (deleteStudent, &QPushButton::clicked, [this,thisClass,studentusername] {removeStudent_clicked(thisClass,studentusername);});

//    QLabel * field = new QLabel;
//    field->setMaximumWidth(81);
//    field->setMaximumHeight(20);
//    field->setText("Field");
//    field->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(studentNumber,0,2);
//    grid->addWidget(field,0,3);
    grid->addWidget(deleteStudent,0,3);


    gBox->setLayout(grid);
    return gBox;
}

void TeacherWatchStudent::removeStudent_clicked(Class thisClass, QString studentusername)
{
    this->mainmenu->deleteStudent(studentusername, thisClass);
}
