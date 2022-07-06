#include "forgotpasspage.h"
#include "ui_forgotpasspage.h"

ForgotPassPage::ForgotPassPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgotPassPage)
{
    ui->setupUi(this);
    this->ui->Confirmbtn->setStyleSheet("background-color:transparent");
}


ForgotPassPage::~ForgotPassPage()
{
    delete ui;
}

void ForgotPassPage::on_Confirmbtn_clicked()
{
    EntereNewPass* enp = new EntereNewPass;
    enp->show();
    close();

}

