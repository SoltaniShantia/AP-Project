#include <QMessageBox>
#include <iostream>
#include<QAbstractButton>


#include "Auth.h"
#include "Filemanager.h"
#include "loginpage.h"
#include "studentmainmenu.h"
#include "adminmainmenu.h"
#include "teachermainmenu.h"

#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->ui->forgotPass->setStyleSheet("background-color:transparent");
    this->ui->Loginbtn->setStyleSheet("background-color:transparent");

    ui->passLine->setEchoMode(QLineEdit::Password);
    connect(ui->showPass, SIGNAL(clicked(bool)), this, SLOT(on_showPass_clicked(bool)));
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_showPass_clicked(bool checked)
{
    if (checked==true){
        ui->passLine->setEchoMode(QLineEdit::Normal);
    }

    else{
        ui->passLine->setEchoMode(QLineEdit::Password);
    }
}


void LoginPage::on_forgotPass_clicked(bool checked)
{
    ForgotPassPage* fpg = new ForgotPassPage;
    fpg->show();
    close();
}

int LoginPage::isUserValid()
{
    QString username = ui->userLine->text();
    QString password = ui->passLine->text();

    return Auth::canLogin(username, password);
}

void LoginPage::on_Loginbtn_clicked()
{
    int userIndex=  isUserValid();


    if(userIndex == -1)
    {
        QMessageBox* loginStatus = new QMessageBox(
            QMessageBox::Critical,
            "Can't Login",
            "Username or password is wrong, please enter valid information.",
            QMessageBox::Ok
            );


        loginStatus->show();
        connect(loginStatus ,
                &QMessageBox::buttonClicked ,
                loginStatus ,
                &QMessageBox::deleteLater
                );
        return;
    }

    FileManager userFile;

    userFile.create();

    userFile.loadData();

    QString wantedUser = userFile.getRecord(userIndex);

    auto parsedUser = userFile.parse(wantedUser);

    QString userType = parsedUser[parsedUser.size() - 1];



    if(userType == "Admin")
    {
        AdminMainMenu* amm = new AdminMainMenu(parsedUser[2]);
        amm->set_username(ui->userLine->text());
        amm->set_first_name(parsedUser[2]);
        amm->set_last_name(parsedUser[3]);
        amm->set_national_code(parsedUser[4]);
        amm->set_phone_number(parsedUser[5]);
        amm->set_role(parsedUser[6]);
        amm->set_password(ui->passLine->text());
        amm->show();
    }
    else if(userType == "Teacher")
    {
        TeacherMainMenu* tmm = new TeacherMainMenu(parsedUser[2] , ui->userLine->text());
//        tmm->set_username(ui->userLine->text());
        tmm->set_first_name(parsedUser[2]);
        tmm->set_last_name(parsedUser[3]);
        tmm->set_national_code(parsedUser[4]);
        tmm->set_phone_number(parsedUser[5]);
        tmm->set_role(parsedUser[6]);
        tmm->set_password(ui->passLine->text());
        tmm->show();

    }
    else if (userType == "Student")
    {
        StudentMainMenu* smm = new StudentMainMenu(parsedUser[2] , parsedUser[0]);
        smm->set_username(ui->userLine->text());
        smm->set_first_name(parsedUser[2]);
        smm->set_last_name(parsedUser[3]);
        smm->set_national_code(parsedUser[4]);
        smm->set_phone_number(parsedUser[5]);
        smm->set_role(parsedUser[6]);
        smm->set_password(ui->passLine->text());
        smm->show();
    }
//    else


    close();
}
