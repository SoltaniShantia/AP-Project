#include "adminwatchmessagecomplitly.h"
#include "adminaddclass.h"
#include "ui_adminwatchmessagecomplitly.h"
#include "adminaddpeople.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminmessages.h"
#include <QMessageBox>
#include "adminclassinfo.h"

adminWatchMessageComplitly::adminWatchMessageComplitly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWatchMessageComplitly)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

    this->ui->TitleLine->setEnabled(false);
    this->ui->SenderLine->setEnabled(false);
    this->ui->messageLine->setEnabled(false);
}

adminWatchMessageComplitly::~adminWatchMessageComplitly()
{
    delete ui;
}

void adminWatchMessageComplitly::on_pushButton_clicked()
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


void adminWatchMessageComplitly::on_pushButton_2_clicked()
{
    adminMessages* as = new adminMessages;
    as->show();
    close();

}


void adminWatchMessageComplitly::on_pushButton_3_clicked()
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


void adminWatchMessageComplitly::on_pushButton_4_clicked()
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


void adminWatchMessageComplitly::on_backToMenu_clicked()
{
    adminMessages* as = new adminMessages;
    as->show();
    close();

}


void adminWatchMessageComplitly::on_pushButton_7_clicked()
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


void adminWatchMessageComplitly::on_pushButton_6_clicked()
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

