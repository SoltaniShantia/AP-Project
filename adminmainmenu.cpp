#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminaddclass.h"
#include "adminclassinfo.h"
#include "adminmessages.h"
#include"teachermainmenu.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <fstream>

using namespace std;

AdminMainMenu::AdminMainMenu( QString firstName , AdminMainMenu * member , QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");

    this->ui->pushButton_3->setStyleSheet("background-color: transparent");

    this->ui->pushButton_4->setStyleSheet("background-color: transparent");

    this->ui->pushButton_7->setStyleSheet("background-color: transparent");

    this->ui->label_14->setStyleSheet("background-color: #f0f0f0; border-radius: 20px");

    this->ui->pushButton_5->setStyleSheet("background-color: transparent");

    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

    this->ui->pushButton_8->setStyleSheet("background-color: transparent");


    this->mainmenu = member;

    if(member!=nullptr)
    {
        this->set_username(mainmenu->get_username());

        this->set_password(mainmenu->get_password());

        this->set_last_name(mainmenu->get_last_name());

        this->set_role(mainmenu->get_role());

        this->set_national_code(mainmenu->get_national_code());

        this->set_phone_number(mainmenu->get_phone_number());
    }

    this->set_first_name(firstName);

    this->ui->label_2->setText("Hi dear " + this->get_first_name());
}


AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

void AdminMainMenu::ending_term()
{
    TeacherMainMenu::cleantecher_lessons();




    QMessageBox * succed = new QMessageBox(QMessageBox::Icon::Information , "Term ended" , "The term ended succesfuly" , QMessageBox::Button::Ok) ;
    succed->show();
    connect(succed , &QMessageBox::buttonClicked , succed , &QMessageBox::deleteLater);
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

        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();

        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }

}


void AdminMainMenu::on_pushButton_clicked()
{    
    AdminProfile* ap = new AdminProfile(this);

    ap->show();

    close();
}


void AdminMainMenu::on_pushButton_4_clicked()
{
    AdminSendAssertion* asa = new AdminSendAssertion(this);

    asa->show();

    close();
}


void AdminMainMenu::on_pushButton_3_clicked()
{
    AdminAddPeople* aap = new AdminAddPeople(this);

    aap->show();

    close();
}


void AdminMainMenu::on_pushButton_2_clicked()
{
    adminMessages* am = new adminMessages(this);

    am->show();

    close();
}


void AdminMainMenu::on_pushButton_7_clicked()
{
    adminAddClass* adc = new adminAddClass(this);

    adc->show();

    close();
}


void AdminMainMenu::on_pushButton_6_clicked()
{
    AdminClassInfo* aci = new AdminClassInfo(this);

    aci->show();

    close();
}


void AdminMainMenu::on_pushButton_8_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Finish term","Do you want to finish the term?");

    exit->setStandardButtons(QMessageBox::Yes);

    exit->addButton(QMessageBox::No);

    exit->setDefaultButton(QMessageBox::No);

    exit->show();

    if(exit->exec() == QMessageBox::Yes){

        ending_term();

        exit->close();

        QString path = "../data_resources/student_term.json";

        ifstream ifs(path.toStdString());

        Json::Value dataHolder;

        Json::Reader dataReader;

        if(dataReader.parse(ifs, dataHolder))
        {
            for(int i = 0; i < dataHolder.size(); i++)
            {
                dataHolder[i]["is_registering"] = true;
            }

            ofstream ofs(path.toStdString());

            Json::StyledWriter writer;

            string serializedData = writer.write(dataHolder);

            ofs << serializedData;

            ofs.close();
        }

        QString path2 = "../data_resources/weeklycalendar.json";

        ifstream ifs2(path2.toStdString());

        if(dataReader.parse(ifs2, dataHolder))
        {
            Json::Value resetWeeklyCalendar;

            resetWeeklyCalendar["students"] = Json::arrayValue;
            resetWeeklyCalendar["teachers"] = Json::arrayValue;
            resetWeeklyCalendar["admins"] = Json::arrayValue;

            ofstream ofs(path2.toStdString());

            Json::StyledWriter writer;

            string serializedData = writer.write(resetWeeklyCalendar);

            ofs << serializedData;

            ofs.close();
        }
    }
    else{
        exit->close();
    }
}

