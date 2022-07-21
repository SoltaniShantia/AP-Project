#include "teachersendassertion.h"
#include "ui_teachersendassertion.h"
#include <QMessageBox>


#include"Notification.h"
#include "teachermainmenu.h"
#include "teacherprofile.h"
#include"Enum.h"
#include"Class.h"

TeacherSendAssertion::TeacherSendAssertion(TeacherMainMenu * tm,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherSendAssertion)

{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->sendbtn->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");

//    connect(ui->StudentBox,&QCheckBox::stateChanged,this,&TeacherSendAssertion::studentReciveState);
//    connect(ui->TeacherBox,&QCheckBox::stateChanged,this,&TeacherSendAssertion::teacherReciveState);

    this->mainmenu = tm ;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());


}

TeacherSendAssertion::~TeacherSendAssertion()
{
    delete ui;
}

void TeacherSendAssertion::studentReciveState(int state)
{
    studentsState = state;
    qDebug()<<state;
}

void TeacherSendAssertion::teacherReciveState(int state)
{
    teachersState = state;
    qDebug()<<state;
}

void TeacherSendAssertion::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* tmm = new TeacherMainMenu(mainmenu->get_first_name(), mainmenu->get_username() , mainmenu );
        tmm->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


void TeacherSendAssertion::on_pushButton_clicked()
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


void TeacherSendAssertion::on_sendbtn_clicked()
{
    /*
     * 0 = PHYSICS
     * 1 = CHEMISTRY
     * 2 = BP
     * 3 = CALCULUS
     * 4 = DISCRETE
     * */
    try
    {
        QString title = ui->TitleLine->text();
        QString message = ui->messageLine->toPlainText();        
        QString ls = this->ui->comboBox->currentText();
        if(ls == "BASIC PROGRAMMING")
            ls = "BP";


//        QList<QString> lessons;
//        lessons.push_back("chemistry");
//        lessons.push_back("math");
//        mainmenu->addNewTeacherToFile(lessons);


        if(mainmenu->lessonIsValid(ls))
        {
            QString lesson = mainmenu->lessonNameCheck(ls);
            Class lessonClass = mainmenu->getLesson(string_to_lesson(lesson));

//            QMap<QString , float> stList;
//            stList.insert("1287237409" , -1);
//            stList.insert("1287237405" , -1);
//            lessonClass.setinformation(string_to_lesson("chemistry") , "talar2" , "11:00" , string_to_day("SUNDAY") , stList);

            mainmenu->sendingNotification(title , message , lessonClass );
            ui->TitleLine->clear();
            ui->messageLine->clear();

        }
        else
            throw std::exception("you don't have this lesson");
    }
    catch(std::exception e)
    {
        emit mainmenu->exceptioOccured(e);
    }
    catch(...)
    {
        std::exception e ("Unknown exception");
        emit mainmenu->exceptioOccured(e);
    }
}

