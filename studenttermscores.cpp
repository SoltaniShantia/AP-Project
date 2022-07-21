#include "studenttermscores.h"
#include "ui_studenttermscores.h"
#include "studentterms.h"
#include "studentprofile.h"
#include "studentmainmenu.h"
#include "studentweeklyschedule.h"
#include "studentteachersurvey.h"
#include "studentenrolment.h"
#include"Auth.h"
#include"Filemanager.h"

StudentTermScores::StudentTermScores(int term , StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentTermScores)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    for (int lesson = 0 ; lesson< mainmenu->getClasses(term).size() ; lesson++){
        ui->verticalLayout_2->addWidget(showScores(lesson , term));

    }
}

StudentTermScores::~StudentTermScores()
{
    delete ui;
}

QGroupBox* StudentTermScores::showScores(int lessonNumber , int term)
{
    QList<QMap<QString , QString>> lesson = mainmenu->getClasses(term);
    int userIndex = Auth::findUser(lesson[lessonNumber]["teacher"]);
    FileManager userFile;
    userFile.create();
    userFile.loadData();

    QVector<QString> parsedUser = userFile.parse(userFile.getRecord(userIndex));

    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * className = new QLabel;
    className->setMaximumWidth(95);
    className->setMaximumHeight(20);
    className->setText(lesson[lessonNumber]["lesson"]);
    className->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * teacherName = new QLabel;
    teacherName->setMaximumWidth(95);
    teacherName->setMaximumHeight(20);
    teacherName->setText(parsedUser[2] + " " + parsedUser[3]);
    teacherName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QLabel * showScore = new QLabel;
    showScore->setMaximumWidth(95);
    showScore->setMaximumHeight(20);
    showScore->setText(lesson[lessonNumber]["score"]);
    showScore->setStyleSheet("font:Montesrat 9px; color: rgb(178, 8, 55);background-color: transparent");


    grid->addWidget(className,0,0);
    grid->addWidget(teacherName,0,1);
    grid->addWidget(showScore,0,2);

    gBox->setLayout(grid);
    return gBox;
}

void StudentTermScores::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile(mainmenu);
        sp->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void StudentTermScores::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentMessages* sm= new studentMessages(mainmenu);
        sm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void StudentTermScores::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentWeeklySchedule* swc = new studentWeeklySchedule(mainmenu);
        swc->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentTermScores::on_pushButton_6_clicked()
{

    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to terms","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTerms* st = new StudentTerms(mainmenu);
        st->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentTermScores::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher survey","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTeacherSurvey* sts = new StudentTeacherSurvey(mainmenu);
        sts->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }


}


void StudentTermScores::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to terms","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTerms* st = new StudentTerms(mainmenu);
        st->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }

}


void StudentTermScores::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to enrolment","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentEnrolment* se = new StudentEnrolment(mainmenu);
        se->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}

