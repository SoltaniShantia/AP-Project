#include "adminaddpeople.h"
#include "adminaddclass.h"
#include "ui_adminaddpeople.h"
#include "adminmainmenu.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include <QMessageBox>
#include "adminmessages.h"
#include "adminclassinfo.h"

AdminAddPeople::AdminAddPeople(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminAddPeople)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->AddBtn->setStyleSheet("background-color: transparent");

}

AdminAddPeople::~AdminAddPeople()
{
    delete ui;
}

void AdminAddPeople::on_backToMenu_clicked()
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


void AdminAddPeople::on_pushButton_clicked()
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


void AdminAddPeople::on_pushButton_4_clicked()
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


void AdminAddPeople::on_pushButton_2_clicked()
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


void AdminAddPeople::on_pushButton_7_clicked()
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


void AdminAddPeople::on_pushButton_6_clicked()
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

