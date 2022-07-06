#include "adminsendassertion.h"
#include "adminaddclass.h"
#include "ui_adminsendassertion.h"
#include <QMessageBox>
#include "adminmainmenu.h"
#include <QCheckBox>
#include "adminprofile.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "adminclassinfo.h"

AdminSendAssertion::AdminSendAssertion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminSendAssertion)
{
    ui->setupUi(this);

    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

    this->ui->sendbtn->setStyleSheet("background-color: transparent");

    connect(ui->AdminBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::adminReciveState);
    connect(ui->StudentBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::studentReciveState);
    connect(ui->TeacherBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::teacherReciveState);
}

AdminSendAssertion::~AdminSendAssertion()
{
    delete ui;
}

void AdminSendAssertion::adminReciveState(int state)
{
    adminsState = state;
    qDebug()<<state;
}

void AdminSendAssertion::studentReciveState(int state)
{
    studentsState = state;
    qDebug()<<state;
}

void AdminSendAssertion::teacherReciveState(int state)
{
    teachersState = state;
    qDebug()<<state;
}







void AdminSendAssertion::on_backToMenu_clicked()
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


void AdminSendAssertion::on_pushButton_clicked()
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


void AdminSendAssertion::on_pushButton_3_clicked()
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


void AdminSendAssertion::on_pushButton_2_clicked()
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


void AdminSendAssertion::on_pushButton_7_clicked()
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


void AdminSendAssertion::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminClassInfo* aci= new AdminClassInfo;
        aci->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}

