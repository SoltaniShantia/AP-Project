#include "enterenewpass.h"
#include "ui_enterenewpass.h"
#include "loginpage.h"

EntereNewPass::EntereNewPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EntereNewPass)
{
    ui->setupUi(this);
    this->ui->Confirmbtn->setStyleSheet("background-color:transparent");
}

EntereNewPass::~EntereNewPass()
{
    delete ui;
}

void EntereNewPass::on_Confirmbtn_clicked()
{
    LoginPage* lg = new LoginPage;
    lg->show();
    close();
}

