#include "adminclassinfo.h"
#include "ui_adminclassinfo.h"
#include <QGridLayout>
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "adminmainmenu.h"
#include "QMessageBox"
#include "adminaddclass.h"
#include "adminwatchstudent.h"


AdminClassInfo::AdminClassInfo(QWidget *parent) :
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

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(watchClass());

    }
}

AdminClassInfo::~AdminClassInfo()
{
    delete ui;
}

QGroupBox *AdminClassInfo::watchClass()
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * className = new QLabel;
    className->setMaximumWidth(210);
    className->setMaximumHeight(20);
    className->setText("Class Name");
    className->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * teacherName = new QLabel;
    teacherName->setMaximumWidth(210);
    teacherName->setMaximumHeight(20);
    teacherName->setText("Teacher Name");
    teacherName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(81);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText("Student Number");
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton* watchBtn = new QPushButton;
    QString Name;
    connect(watchBtn,&QPushButton::clicked,[this, Name] { goToClassInfo(Name);});
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

void AdminClassInfo::goToClassInfo(QString className)
{
    AdminWatchStudent* aws = new AdminWatchStudent;
    aws->show();
    close();

}

void AdminClassInfo::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu;
        amm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void AdminClassInfo::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminProfile* ap= new AdminProfile;
        ap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void AdminClassInfo::on_pushButton_2_clicked()
{

    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to messages","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminMessages* as = new adminMessages;
        as->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void AdminClassInfo::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add people","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminAddPeople* aap= new AdminAddPeople;
        aap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void AdminClassInfo::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion;
        asa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void AdminClassInfo::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add class","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminAddClass* adc= new adminAddClass;
        adc->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}

