#include"Auth.h"
#include "ui_forgotpasspage.h"
#include "forgotpasspage.h"
#include "loginpage.h"


#include<QMessageBox>


ForgotPassPage::ForgotPassPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgotPassPage)
{
    ui->setupUi(this);

    this->ui->Confirmbtn->setStyleSheet("background-color: transparent");

    this->ui->backToLogin->setStyleSheet("background-color: transparent");
}


ForgotPassPage::~ForgotPassPage()
{
    delete ui;
}

void ForgotPassPage::on_Confirmbtn_clicked()
{
    QString phoneNumber = ui->phoneLine->text() ;
    QString username = ui->userLine->text() ;

    int index = Auth::isHintValid(username , phoneNumber);

    if (!(index > -1))
    {
        QMessageBox * noUserFound = new QMessageBox(QMessageBox::Icon::Critical , "Invalid usernme or phone number" , "the usernme or phone number doesn't match or doesn't exist at all. please check your answers again" , QMessageBox::Button::Ok);

        QObject::connect(noUserFound , &QMessageBox::buttonClicked , noUserFound , &QMessageBox::deleteLater);

        noUserFound->show();

        return;
    }
    
    EntereNewPass* enp = new EntereNewPass;

    enp->setIndex(index);

    enp->show();
    close();

}


void ForgotPassPage::on_backToLogin_clicked()
{
    qDebug() << "Hello";

    LoginPage* lp = new LoginPage;

    lp->show();

    close();
}

