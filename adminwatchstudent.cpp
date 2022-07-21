#include "adminwatchstudent.h"
#include "ui_adminwatchstudent.h"
#include "adminclassinfo.h"
#include <QGridLayout>
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "adminmainmenu.h"
#include "QMessageBox"
#include "Filemanager.h"
#include "Auth.h"
#include "adminaddclass.h"
#include <fstream>

using namespace std;

AdminWatchStudent::AdminWatchStudent(AdminMainMenu * member, Class classToShow , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWatchStudent)
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
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    this->ui->label_20->setText(mainmenu->get_first_name()+ " " + mainmenu->get_last_name());
    this->ui->label_17->setText(QString::fromStdString(to_string(classToShow.getStudentNum())));
    this->ui->label_16->setText(lesson_enum_str[classToShow.getLesson()]);

    QList<QString> usernameList = classToShow.getList().keys();
    for (int i = 0 ; i<classToShow.getStudentNum();i++){

        int userIndex = Auth::findUser(usernameList[i]);

        FileManager userFile;
        userFile.create();
        userFile.loadData();

        QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

        ui->verticalLayout_2->addWidget(students(parsedUser[2],parsedUser[3],usernameList[i], classToShow));

    }

}

AdminWatchStudent::~AdminWatchStudent()
{
    delete ui;
}

void AdminWatchStudent::on_pushButton_clicked()
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


void AdminWatchStudent::on_pushButton_2_clicked()
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


void AdminWatchStudent::on_pushButton_3_clicked()
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


void AdminWatchStudent::on_pushButton_4_clicked()
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


void AdminWatchStudent::on_pushButton_7_clicked()
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


void AdminWatchStudent::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminClassInfo* aci = new AdminClassInfo(mainmenu);
        aci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void AdminWatchStudent::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminClassInfo* aci = new AdminClassInfo(mainmenu);
        aci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }


}

QGroupBox *AdminWatchStudent::students(QString firstname,QString lastname,QString studentusername, Class thisClass)
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

    QPushButton* deleteStudentUser = new QPushButton;
    deleteStudentUser->setMaximumWidth(81);
    deleteStudentUser->setMaximumHeight(20);
    deleteStudentUser->setText("remove user");

    connect (deleteStudentUser, &QPushButton::clicked, [this,thisClass,studentusername] {removeStudentUser_clicked(thisClass,studentusername);});

//    QLabel * field = new QLabel;
//    field->setMaximumWidth(81);
//    field->setMaximumHeight(20);
//    field->setText("Field");
//    field->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(studentNumber,0,2);
//    grid->addWidget(field,0,3);
    grid->addWidget(deleteStudentUser,0,3);


    gBox->setLayout(grid);
    return gBox;
}


void AdminWatchStudent::removeStudentUser_clicked(Class thisClass, QString studentusername)
{

    QString SfilePath = "../data_resources/student_term.json";
    Json::Value SdataHolder;
    Json::Reader SdataReader;

    if(thisClass.studentIsValid(studentusername))
    {
        thisClass.deleteStudent(studentusername);

        ifstream ifs(SfilePath.toStdString());

        if(SdataReader.parse(ifs, SdataHolder))
        {

            Json::Value wantedUsers;

            for(int i = 0; i < SdataHolder.size(); i++)
            {
                if(studentusername.toStdString() != SdataHolder[i]["username"].asString())
                {
                    int Term = SdataHolder[i]["count_of_terms"].asInt()-1;
                    Json::Value classesCopy = SdataHolder[i]["terms"][Term]["lessons"];

                    for(int l = 0; l < classesCopy.size(); l++){
                        Class studentClass (string_to_lesson( QString::fromStdString(classesCopy[l]["lesson"].asString())),QString::fromStdString(classesCopy[l]["teacher"].asString()) );
                        studentClass.deleteStudent(studentusername);
                    }


                    wantedUsers.append(SdataHolder[i]);

                    ofstream ofs(SfilePath.toStdString());

                    Json::StyledWriter writer;

                    string serializedData = writer.write(wantedUsers);
                    ofs << serializedData;
                    ofs.close();

                    break;
                }
            }
        }
    }

    int userIndex = Auth::findUser(studentusername);

            FileManager userFile;
            userFile.create();
            userFile.loadData();

            userFile.deleteRecord(userIndex);
            userFile.write();

     QMessageBox * studentdeleted = new QMessageBox(QMessageBox::Icon::Information, "User deleted", "the student was deleted succesfuly", QMessageBox::Button::Ok);
     studentdeleted->show();
     QObject::connect(studentdeleted , &QMessageBox::buttonClicked , studentdeleted , &QMessageBox::deleteLater);

}
