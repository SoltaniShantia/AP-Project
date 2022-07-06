#include "sendassertionadmin.h"
#include "ui_sendassertionadmin.h"

sendAssertionAdmin::sendAssertionAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sendAssertionAdmin)
{
    ui->setupUi(this);
}

sendAssertionAdmin::~sendAssertionAdmin()
{
    delete ui;
}
