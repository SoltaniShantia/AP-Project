#include "teacherstudentsetscore.h"
#include "ui_teacherstudentsetscore.h"
#include "teacherclasssetscore.h"
#include "teachermainmenu.h"
#include "teacherclassinfo.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermessages.h"
#include "teacherweeklyschedule.h"
#include "QLineEdit"
#include <QDoubleValidator>
#include "Auth.h"
#include "Filemanager.h"

TeacherStudentSetScore::TeacherStudentSetScore(TeacherMainMenu * member , Class thisClass, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherStudentSetScore)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");
    this->ui->SetScore->setStyleSheet("background-color:transparent");

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    QList<QString> usernameList = thisClass.getList().keys();


    for (int i = 0 ; i < thisClass.getStudentNum(); i++){

        int userIndex = Auth::findUser(usernameList[i]);
        FileManager userFile;
        userFile.create();
        userFile.loadData();
        QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

        ui->verticalLayout_2->addWidget(showStudent(parsedUser[2],parsedUser[3],usernameList[i], thisClass));


    }


}

TeacherStudentSetScore::~TeacherStudentSetScore()
{
    delete ui;
}

QGroupBox *TeacherStudentSetScore::showStudent(QString firstname,QString lastname,QString studentusername, Class thisClass)
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * Name = new QLabel;
    Name->setMaximumWidth(80);
    Name->setMaximumHeight(20);
    Name->setText(firstname);
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(80);
    lastName->setMaximumHeight(20);
    lastName->setText(lastname);
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(80);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText(studentusername);
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


//    QLabel * field = new QLabel;
//    field->setMaximumWidth(80);
//    field->setMaximumHeight(20);
//    field->setText("Field");
//    field->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLineEdit* score = new QLineEdit;
    score->setMaximumWidth(50);
    score->setMaximumHeight(20);
    score->setMaxLength(5);
    auto dv = new QDoubleValidator(0.00, 20.00, 3);
    score->setValidator(dv);

    QPushButton* setScore = new QPushButton;
    setScore->setText("set score");

    float newScore = score->text().toFloat();

    connect(score, &QLineEdit::textChanged, [this, score] { this->score = score->text().toFloat(); });

    connect (setScore, &QPushButton::clicked, [this,thisClass,studentusername, newScore] {SetScore_clicked(thisClass,studentusername, newScore);});


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(studentNumber,0,2);
//    grid->addWidget(field,0,3);
    grid->addWidget(score,0,3);
    grid->addWidget(setScore,0,4);


    gBox->setLayout(grid);
    return gBox;

}

void TeacherStudentSetScore::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile(mainmenu);
        tp->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherStudentSetScore::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherMessages* tm= new teacherMessages(mainmenu);
        tm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherStudentSetScore::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassInfo* tci = new TeacherClassInfo(mainmenu);
        tci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherStudentSetScore::on_pushButton_4_clicked()
{

    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion;
        tsa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void TeacherStudentSetScore::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule(mainmenu);
        tws->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherStudentSetScore::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to set score","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassSetScore* tcss = new TeacherClassSetScore(mainmenu);
        tcss->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void TeacherStudentSetScore::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to set score","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassSetScore* tcss = new TeacherClassSetScore(mainmenu);
        tcss->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}




void TeacherStudentSetScore::SetScore_clicked(Class studentClass, QString S_username, float score)

{

    studentClass.setScore(S_username, this->score);
}

