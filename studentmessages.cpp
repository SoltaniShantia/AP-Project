#include "studentmessages.h"
#include "ui_studentmessages.h"
#include "studentmainmenu.h"
#include "studentprofile.h"
#include <QMessageBox>
#include "studentwatchmessagecomplitly.h"
#include "studentweeklyschedule.h"
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGridLayout>
#include <QWidget>
#include <QListWidget>

studentMessages::studentMessages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentMessages)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(showMessages(i));

    }


}

studentMessages::~studentMessages()
{
    delete ui;
}

QGroupBox* studentMessages::showMessages(int i)
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

void studentMessages::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile;
        sp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void studentMessages::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu;
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}



void studentMessages::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentWeeklySchedule* swc = new studentWeeklySchedule;
        swc->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}

void studentMessages::on_msgBtn_clicked(QString title)
{

    StudentWatchMessageComplitly* swmc = new StudentWatchMessageComplitly;
    swmc->show();
    close();
}

