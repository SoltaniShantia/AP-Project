#include "adminsendassertion.h"
#include "ui_adminsendassertion.h"
#include <QMessageBox>
#include "adminmainmenu.h"
#include <QCheckBox>
#include "adminprofile.h"
#include "adminaddpeople.h"
#include"Notification.h"

AdminSendAssertion::AdminSendAssertion(AdminMainMenu * recievedmember , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminSendAssertion)
{
    ui->setupUi(this);

    this->ui->pushButton->setStyleSheet("background-color: transparent");
//    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->sendbtn->setStyleSheet("background-color: transparent");

//    connect(ui->AdminBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::adminReciveState);
    connect(ui->StudentBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::studentReciveState);    
    connect(ui->TeacherBox,&QCheckBox::stateChanged,this,&AdminSendAssertion::teacherReciveState);

    this->mainmenu = recievedmember;

    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name() );


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
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() ,mainmenu);
        amm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }
}


void AdminSendAssertion::on_pushButton_clicked()
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


void AdminSendAssertion::on_pushButton_3_clicked()
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


void AdminSendAssertion::on_sendbtn_clicked()
{
    int teacherChosen = this->ui->TeacherBox->isChecked();
    int studentChosen = this->ui->StudentBox->isChecked();   

    QString title = ui->TitleLine->text();
    QString message = ui->messageLine->toPlainText();

    if(teacherChosen == 0 && studentChosen == 0)
    {
        QMessageBox * choosesth = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "Choose the reciever first" , QMessageBox::Button::Ok);
        choosesth->show();
        connect(choosesth , &QMessageBox::buttonClicked ,  choosesth , &QMessageBox::deleteLater ) ;
        return ;
    }

    Notification alert;
    if (studentChosen == 1 && teacherChosen == 1)
        alert.addNotif(title , message , mainmenu->get_username());
    else if(studentChosen == 1)
        alert.addNotif(title , message , mainmenu->get_username() , "S");
    else if(teacherChosen == 1)
        alert.addNotif(  title , message , mainmenu->get_username() , "T") ;


}

