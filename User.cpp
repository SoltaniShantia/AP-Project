#include<QMessageBox>
#include<QAbstractButton>
#include<iostream>
using namespace std;


#include "User.h"


User::User(QWidget *parent)
    : QWidget{parent}
{
    connect(this , &User::exceptioOccured , this , &User::exceptionHandling );
}

void User::set_first_name(QString name)
{
    this->first_name = name;
}

void User::set_last_name(QString name)
{
    this->last_name = name ;
}

void User::set_national_code(QString national)
{
    this->national_code = national;
}

void User::set_phone_number(QString phone)
{
    this->phone_number = phone ;
}

void User::set_role(QString _role)
{
    this->role = _role ;
}

void User::set_hint(QString _hint)
{
    this->hint = _hint;
}

void User::set_username(QString user)
{
    this->username = user ;
}

void User::set_password(QString pass)
{
    this->password = pass ;

}

QString User::get_national_code()
{
    return this->national_code ;
}

QString User::get_phone_number()
{
    return this->phone_number ;
}

QString User::get_role()
{
    return this->role;
}

QString User::get_hint()
{
    return this->hint;
}

QString User::get_username()
{
    return this->username ;
}

QString User::get_password()
{
    return this->password ;
}

void User::exceptionHandling(std::exception e)
{
    QMessageBox * errorMessage = new QMessageBox(QMessageBox::Icon::Critical , "Error occured" , e.what() , QMessageBox::Button::Ok ) ;
    errorMessage->show();
    connect(errorMessage , &QMessageBox::buttonClicked , errorMessage , &QMessageBox::deleteLater);
}

QString User::get_first_name()
{
    return this->first_name ;
}

QString User::get_last_name()
{
    return this->last_name ;
}
