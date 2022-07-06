#include "teacherprofile.h"
#include "teacherclassinfo.h"
#include <QValidator>
#include "ui_teacherprofile.h"
#include <QMessageBox>
#include "teachersendassertion.h"
#include "teachermainmenu.h"
#include "teachermessages.h"
#include "teacherweeklyschedule.h"

teacherProfile::teacherProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherProfile)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");

    this->ui->applychng->setStyleSheet("background-color: transparent");
    this->ui->applychng_2->setStyleSheet("background-color: transparent");
    this->ui->chngPass->setStyleSheet("background-color: transparent");
    this->ui->chngNumber->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->applychng_2->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);

    this->ui->applychng->setVisible(false);
    this->ui->label_20->setVisible(false);



    this->ui->nameLine->setText("Shantia");
    this->ui->nameLine->setDisabled(true);
    this->ui->lastNameLine->setText("Soltani");
    this->ui->lastNameLine->setDisabled(true);
    this->ui->NcodeLine->setText("123456789");
    this->ui->NcodeLine->setDisabled(true);
    this->ui->RoleLine->setText("Admin");
    this->ui->RoleLine->setDisabled(true);
    this->ui->numberLine->setText("0910 209 8097");
    this->ui->numberLine->setDisabled(true);
    this->ui->numberLine->setValidator(new QIntValidator(this));
}

teacherProfile::~teacherProfile()
{
    delete ui;
}

void teacherProfile::on_applychng_clicked()
{
    this->ui->applychng->setVisible(false);
    this->ui->label_20->setVisible(false);
    this->ui->numberLine->setDisabled(true);
}


void teacherProfile::on_chngNumber_clicked()
{
    this->ui->applychng->setVisible(true);
    this->ui->label_20->setVisible(true);
    this->ui->numberLine->setDisabled(false);
}


void teacherProfile::on_chngPass_clicked()
{
    this->ui->applychng_2->setVisible(true);
    this->ui->label_24->setVisible(true);
    this->ui->changePass->setVisible(true);
}


void teacherProfile::on_applychng_2_clicked()
{
    this->ui->applychng_2->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);
}


void teacherProfile::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* smm = new TeacherMainMenu;
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherProfile::on_pushButton_4_clicked()
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


void teacherProfile::on_pushButton_2_clicked()
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


void teacherProfile::on_pushButton_5_clicked()
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


void teacherProfile::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
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

