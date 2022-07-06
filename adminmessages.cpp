#include "adminmessages.h"
#include "adminaddclass.h"
#include "ui_adminmessages.h"
#include <QMessageBox>
#include "adminaddpeople.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminmainmenu.h"
#include "adminwatchmessagecomplitly.h"
#include "adminclassinfo.h"


adminMessages::adminMessages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminMessages)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(showMessages(i));

    }

}

adminMessages::~adminMessages()
{
    delete ui;
}

QGroupBox *adminMessages::showMessages(int i)
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * msgTitle = new QLabel;
    msgTitle->setMaximumWidth(81);
    msgTitle->setMaximumHeight(20);
    msgTitle->setText("Title");
    msgTitle->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * msg = new QLabel;
    msg->setMaximumWidth(421);
    msg->setMaximumHeight(20);
    msg->setText("Message");
    msg->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton* watchBtn = new QPushButton;
    QString title;
    connect(watchBtn,&QPushButton::clicked,[this, title] { on_msgBtn_clicked(title);});
    watchBtn->setMaximumWidth(101);
    watchBtn->setMaximumHeight(26);
    watchBtn->setText("Watch More");
    watchBtn->setStyleSheet("background-color: transparent;color:rgb(178, 8, 55);");


    grid->addWidget(msgTitle,0,0);
    grid->addWidget(msg,0,1);
    grid->addWidget(watchBtn,0,2);

    gBox->setLayout(grid);
    return gBox;

}

void adminMessages::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminProfile* ap= new AdminProfile;
        ap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void adminMessages::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add people","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminAddPeople* aap= new AdminAddPeople;
        aap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void adminMessages::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion;
        asa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void adminMessages::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu;
        amm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}



void adminMessages::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add class","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminAddClass* adc= new adminAddClass;
        adc->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}

void adminMessages::on_msgBtn_clicked(QString title)
{
    adminWatchMessageComplitly* awmc = new adminWatchMessageComplitly;
    awmc->show();
    close();

}


void adminMessages::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminClassInfo* aci= new AdminClassInfo;
        aci->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}

