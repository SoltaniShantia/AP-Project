#include "loginpage.h"
#include "ui_loginpage.h"
#include "studentmainmenu.h"
#include "adminmainmenu.h"
#include "teachermainmenu.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->ui->forgotPass->setStyleSheet("background-color:transparent");
    this->ui->Loginbtn->setStyleSheet("background-color:transparent");

    ui->passLine->setEchoMode(QLineEdit::Password);
    connect(ui->showPass,SIGNAL(clicked(bool)),this,SLOT(on_showPass_clicked(bool)));


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


void LoginPage::on_forgotPass_clicked()
{
    ForgotPassPage* fpg = new ForgotPassPage;
    fpg->show();
    close();
}





void LoginPage::on_Loginbtn_clicked()
{
    /*StudentMainMenu* smm = new StudentMainMenu;
    smm->show();
    close();*/

    /*TeacherMainMenu* tmm = new TeacherMainMenu;
    tmm->show();
    close();*/

    AdminMainMenu* amm = new AdminMainMenu;
    amm->show();
    close();
}

