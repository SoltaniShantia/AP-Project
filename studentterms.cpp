#include "studentterms.h"
#include "ui_studentterms.h"
#include "studentprofile.h"
#include "studentmainmenu.h"
#include "studentweeklyschedule.h"
#include "studentteachersurvey.h"
#include "studenttermscores.h"
#include "studenttermscores.h"
#include "studentenrolment.h"

StudentTerms::StudentTerms(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentTerms)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member ;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    for (int terms = 0 ; terms<mainmenu->getTerm();terms++){
        ui->verticalLayout_2->addWidget(showTerms(terms));

    }
}

StudentTerms::~StudentTerms()
{
    delete ui;
}

QGroupBox *StudentTerms::showTerms(int term)
{
    QList<float> averages = mainmenu->getAverages();
    if(averages.size() < 1)
    {
        mainmenu->load();
        averages = mainmenu->getAverages();
    }
    QString average = QString::number(averages[term]);
    if(static_cast<int>(averages[term]) == -1)
        average = "not registered yet" ;



    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * termName = new QLabel;
    termName->setMaximumWidth(81);
    termName->setMaximumHeight(20);
    termName->setText(QString::number(term + 1 ));
    termName->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * termAverage = new QLabel;
    termAverage->setMaximumWidth(95);
    termAverage->setMaximumHeight(20);
    termAverage->setText(average);
    termAverage->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QPushButton * showScore = new QPushButton;
    QString nameOfTerm;
    showScore->setMaximumWidth(81);
    showScore->setMaximumHeight(20);
    showScore->setText("Watch Scores");
    showScore->setStyleSheet("font:Montesrat 9px; color: rgb(178, 8, 55);background-color: transparent");
    connect(showScore,&QPushButton::clicked,[this, term] { goToScores(term);});


    grid->addWidget(termName,0,0);
    grid->addWidget(termAverage,0,1);
    grid->addWidget(showScore,0,2);

    gBox->setLayout(grid);
    return gBox;


}

void StudentTerms::on_pushButton_clicked()
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


void StudentTerms::on_pushButton_2_clicked()
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


void StudentTerms::on_pushButton_3_clicked()
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


void StudentTerms::on_pushButton_7_clicked()
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


void StudentTerms::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu->get_first_name() , mainmenu->get_username() , mainmenu);
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

void StudentTerms::goToScores(int term)
{
    StudentTermScores* sts = new StudentTermScores(term , mainmenu);
    sts->show();
    close();
}


void StudentTerms::on_pushButton_4_clicked()
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

