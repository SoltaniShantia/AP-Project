#include <QMessageBox>

#include "Filemanager.h"
#include "Auth.h"
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

void EntereNewPass::setIndex(int _index)
{
    this->index = _index;
}

void EntereNewPass::on_Confirmbtn_clicked()
{
    QString newPass = ui->newPass->text();
    QString confirmNewPass = ui->confirmNewPass->text();

    if (newPass != confirmNewPass)
    {
        QMessageBox * confirmPassDoesntMatch = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
        confirmPassDoesntMatch->show();
        connect(confirmPassDoesntMatch , &QMessageBox::buttonClicked , confirmPassDoesntMatch, &QMessageBox::deleteLater);
        return;
    }

//    FileManager userFile;

//    userFile.create();

//    userFile.loadData();

//    QVector<QString> parsedUserInfo = userFile.parse(userFile.getRecord(index));

//    parsedUserInfo[1] = newPass;

//    QString modifiedUserInfo = Auth::formUserData(
//        parsedUserInfo[0], parsedUserInfo[1],
//        parsedUserInfo[2], parsedUserInfo[3],
//        parsedUserInfo[4], parsedUserInfo[5],
//        parsedUserInfo[6]
//    );

//    userFile.update(index, modifiedUserInfo);

//    userFile.write();

    Auth::updateCredential(index, 1, newPass, true);

    QMessageBox * passwordChanged = new QMessageBox(QMessageBox::Icon::Information, "Password Changed", "your password changed successfuly", QMessageBox::Button::Ok);
    passwordChanged->setParent(this);

    passwordChanged->show();

    connect(passwordChanged , &QMessageBox::buttonClicked , passwordChanged , &QMessageBox::deleteLater);

    LoginPage* lg = new LoginPage;

    connect(passwordChanged, &QMessageBox::buttonClicked, lg, &LoginPage::show);

    connect(passwordChanged, &QMessageBox::buttonClicked, this, &EntereNewPass::close);
}

