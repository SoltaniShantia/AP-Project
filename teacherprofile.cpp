#include "teacherprofile.h"
#include "ui_teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermainmenu.h"
#include "Auth.h"
#include "Filemanager.h"
#include "Md5Hash.h"

#include <QValidator>
#include <QRegularExpression>
#include <QMessageBox>

teacherProfile::teacherProfile(TeacherMainMenu * member , QWidget *parent) :
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

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    this->ui->nameLine->setText(mainmenu->get_first_name());
    this->ui->nameLine->setDisabled(true);
    this->ui->lastNameLine->setText(mainmenu->get_last_name());
    this->ui->lastNameLine->setDisabled(true);
    this->ui->nationalCodeLine->setText(mainmenu->get_national_code());
    this->ui->nationalCodeLine->setDisabled(true);
    this->ui->roleLine->setText(mainmenu->get_role());
    this->ui->roleLine->setDisabled(true);
    this->ui->numberLine->setText(mainmenu->get_phone_number());
    this->ui->numberLine->setDisabled(true);


    // added Iranian phone number validator with help of regex :)
    this->ui->numberLine->setValidator(new QRegularExpressionValidator(QRegularExpression(R"((0|\+98)?([ ]|-|[()]){0,2}9[1|2|3|4]([ ]|-|[()]){0,2}(?:[0-9]([ ]|-|[()]){0,2}){8})"), this));
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

    QString newPhoneNumber = ui->numberLine->text();

    int userIndex = Auth::findUser(this->mainmenu->get_username());

    Auth::updateCredential(userIndex, 5, newPhoneNumber);

    QMessageBox* phoneNumberChanged = new QMessageBox(QMessageBox::Icon::Information, "Phone Number Changed", "your phone number changed successfuly", QMessageBox::Button::Ok);

    phoneNumberChanged->show();

    connect(phoneNumberChanged , &QMessageBox::buttonClicked , phoneNumberChanged , &QMessageBox::deleteLater);

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


    this->ui->applychng_2->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);
}


void teacherProfile::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* smm = new TeacherMainMenu(mainmenu->get_first_name() , mainmenu->get_username() ,  mainmenu );
        smm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void teacherProfile::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion(mainmenu);
        tsa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}

