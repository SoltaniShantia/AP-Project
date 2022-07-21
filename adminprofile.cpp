#include "adminprofile.h"
#include "ui_adminprofile.h"
#include "adminmainmenu.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "Auth.h"
#include "Filemanager.h"
#include "Md5Hash.h"

#include <QMessageBox>
#include <QValidator>
#include <QRegularExpressionValidator>

AdminProfile::AdminProfile(AdminMainMenu * adminMainMenuMember, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminProfile)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->applyChangeNumber->setStyleSheet("background-color: transparent");
    this->ui->applyChangePass->setStyleSheet("background-color: transparent");
    this->ui->changePassBtn->setStyleSheet("background-color: transparent");
    this->ui->changeNumber->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");


    this->ui->applyChangePass->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);

    this->ui->applyChangeNumber->setVisible(false);
    this->ui->label_20->setVisible(false);

    this->mainmenu = adminMainMenuMember;

    this->ui->nameLine->setText(mainmenu->get_first_name());
    this->ui->nameLine->setDisabled(true);
    this->ui->lastNameLine->setText(mainmenu->get_last_name());
    this->ui->lastNameLine->setDisabled(true);
    this->ui->NcodeLine->setText(mainmenu->get_national_code());
    this->ui->NcodeLine->setDisabled(true);
    this->ui->RoleLine->setText(mainmenu->get_role());
    this->ui->RoleLine->setDisabled(true);
    this->ui->numberLine->setText(mainmenu->get_phone_number());

    this->ui->numberLine->setDisabled(true);

    // added Iranian phone number validator with help of regex :)
    this->ui->numberLine->setValidator(new QRegularExpressionValidator(QRegularExpression(R"((0|\+98)?([ ]|-|[()]){0,2}9[1|2|3|4]([ ]|-|[()]){0,2}(?:[0-9]([ ]|-|[()]){0,2}){8})"), this));

    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());
}

AdminProfile::~AdminProfile()
{
    delete ui;
}

void AdminProfile::on_changeNumber_clicked()
{
    this->ui->numberLine->setDisabled(false);
    this->ui->applyChangeNumber->setVisible(true);
    this->ui->label_20->setVisible(true);
}


void AdminProfile::on_applyChangeNumber_clicked()
{
    this->ui->numberLine->setDisabled(true);
    this->ui->applyChangeNumber->setVisible(false);
    this->ui->label_20->setVisible(false);

    QString newPhoneNumber = ui->numberLine->text();

    int userIndex = Auth::findUser(this->mainmenu->get_username());

    Auth::updateCredential(userIndex, 5, newPhoneNumber);

    QMessageBox* phoneNumberChanged = new QMessageBox(QMessageBox::Icon::Information, "Phone Number Changed", "your phone number changed successfuly", QMessageBox::Button::Ok);

    phoneNumberChanged->show();

    connect(phoneNumberChanged , &QMessageBox::buttonClicked , phoneNumberChanged , &QMessageBox::deleteLater);
}


void AdminProfile::on_applyChangePass_clicked()
{
    FileManager userFile;

    userFile.create();

    userFile.loadData();

    QString oldPassword = ui->oldPass->text();

    QString newPassword = ui->newPass->text();

    QString confirmNewPassword = ui->confirmNewPass->text();

    int userIndex = Auth::findUser(this->mainmenu->get_username());

    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

    if(parsedUser.at(1) != QString::fromStdString(md5(oldPassword.toStdString())))
    {
        QMessageBox* wrongPassword = new QMessageBox(QMessageBox::Icon::Critical, "Wrong Password", "entered current password doesnt match.", QMessageBox::Button::Ok);

        wrongPassword->show();

        connect(wrongPassword , &QMessageBox::buttonClicked , wrongPassword , &QMessageBox::deleteLater);

        return;
    }

    if(newPassword != confirmNewPassword)
    {
        QMessageBox* wrongPasswordConfirm = new QMessageBox(QMessageBox::Icon::Critical, "Passwords Doesnt Match", "new password and confirm new password doesnt match.", QMessageBox::Button::Ok);

        wrongPasswordConfirm->show();

        connect(wrongPasswordConfirm , &QMessageBox::buttonClicked , wrongPasswordConfirm , &QMessageBox::deleteLater);

        return;
    }

    Auth::updateCredential(userIndex, 1, newPassword, true);

    QMessageBox* passwordChanged = new QMessageBox(QMessageBox::Icon::Information, "Password Changed", "your password changed successfuly.", QMessageBox::Button::Ok);

    passwordChanged->show();

    connect(passwordChanged , &QMessageBox::buttonClicked , passwordChanged , &QMessageBox::deleteLater);

    this->ui->changePass->setVisible(false);
    this->ui->applyChangePass->setVisible(false);
    this->ui->label_24->setVisible(false);
}


void AdminProfile::on_changePassBtn_clicked()
{
    this->ui->changePass->setVisible(true);
    this->ui->applyChangePass->setVisible(true);
    this->ui->label_24->setVisible(true);
}


void AdminProfile::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() , mainmenu);
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


void AdminProfile::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion;
        asa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }
}


void AdminProfile::on_pushButton_3_clicked()
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

