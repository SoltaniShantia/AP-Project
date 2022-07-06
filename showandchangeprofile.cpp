#include "showandchangeprofile.h"
#include "ui_showandchangeprofile.h"

ShowAndChangeProfile::ShowAndChangeProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowAndChangeProfile)
{
    ui->setupUi(this);
}

ShowAndChangeProfile::~ShowAndChangeProfile()
{
    delete ui;
}
