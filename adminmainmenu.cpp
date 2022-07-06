#include "adminmainmenu.h"
#include "adminaddclass.h"
#include "ui_adminmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "adminclassinfo.h"

AdminMainMenu::AdminMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->label_14->setStyleSheet("background-color: #f0f0f0; border-radius: 20px");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

void AdminMainMenu::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}





void AdminMainMenu::on_pushButton_clicked()
{
    AdminProfile* ap = new AdminProfile;
    ap->show();
    close();
}


void AdminMainMenu::on_pushButton_4_clicked()
{
    AdminSendAssertion* asa = new AdminSendAssertion;
    asa->show();
    close();
}


void AdminMainMenu::on_pushButton_3_clicked()
{
    AdminAddPeople* aap = new AdminAddPeople;
    aap->show();
    close();
}


void AdminMainMenu::on_pushButton_2_clicked()
{
    adminMessages* as = new adminMessages;
    as->show();
    close();
}


void AdminMainMenu::on_pushButton_7_clicked()
{
    adminAddClass* adc = new adminAddClass;
    adc->show();
    close();
}


void AdminMainMenu::on_pushButton_6_clicked()
{
    AdminClassInfo* aci = new AdminClassInfo;
    aci->show();
    close();

}

