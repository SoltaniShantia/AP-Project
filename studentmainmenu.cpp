#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <iterator>
#include <string>
#include <fstream>

#include"studentmessages.h"
#include "studentmainmenu.h"
#include "ui_studentmainmenu.h"
#include "loginpage.h"
#include "studentprofile.h"
#include "Enum.h"
#include"studentweeklyschedule.h"
#include "studentmessages.h"
#include "studentenrolment.h"
#include "studentteachersurvey.h"
#include "studentterms.h"
#include "studentteachersurvey.h"


using std::ifstream, std::string, std::ofstream;

StudentMainMenu::StudentMainMenu(QString firstname , QString username , StudentMainMenu * member ,  QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::StudentMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->label_8->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");

    this->mainmenu = member;
    if (member!=nullptr)
    {
        this->set_username(mainmenu->get_username());
        this->set_password(mainmenu->get_password());
        this->set_last_name(mainmenu->get_last_name());
        this->set_role(mainmenu->get_role());
        this->set_national_code(mainmenu->get_national_code());
        this->set_phone_number(mainmenu->get_phone_number());
    }

    this->set_first_name(firstname);
    this->set_username(username);
    this->ui->label_2->setText("Hi dear " + firstname);

    load();

//    QString filePath = "../data_resources/student_term.json";

//    ifstream ifs(filePath.toStdString());

//    if(dataReader.parse(ifs, dataHolder))
//    {
//        for(int i = 0; i < dataHolder.size(); i++)
//        {
//            if(get_username().toStdString() == dataHolder[i]["username"].asString())
//            {
//                this->Term = dataHolder[i]["count_of_terms"].asInt();

//                for( int j=0; j < dataHolder[i]["terms"].size(); j++ ){
//                    avereges.push_back(dataHolder[i]["terms"][j]["average"].asFloat());
//                }
//                this->currentAverege = avereges[Term-1];
//                ifs.close();
//                return;
//            }
//        }
//    }

}

StudentMainMenu::~StudentMainMenu()
{
    delete ui;
}

QList<float> StudentMainMenu::getAverages()
{

    return avereges;
}

QMap <QString, float> StudentMainMenu::getScores(int chosenTerm)
{

    QMap <QString, float> scores_list;

    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                Json::Value chosenTermClasses = dataHolder[i]["terms"][chosenTerm]["lessons"];

                for(int j = 0; j < chosenTermClasses.size(); j++)
                {
                    scores_list.insert(QString::fromStdString(chosenTermClasses[i]["lesson"].asString()),chosenTermClasses[i]["score"].asFloat());
                }

                ifs.close();
                return scores_list;
            }
        }
//student not found
    }
}


void StudentMainMenu::surveyOfTeachers(Class Class, int result)
{
    //    Class.addSurveyResult(this->get_username(), result);
}

//bool StudentMainMenu:: is_equal(Class i){i.getLesson() == lesson.getLesson();}

//void StudentMainMenu::deleteLesson(Class lesson)
//{
////    QMultiMap <Class, float> helper;
////    for(auto i=this_term_classes.cbegin(); i!=this_term_classes.cend(); i++){
////        helper.insert(i.key(),i.value());
//////        helper[i.key()]=i.value();
////    }
////    this_term_classes.erase(this_term_classes.begin(),this_term_classes.end());

////    for(auto j=helper.begin(); j!=helper.end(); j++){
////        auto &class_to_delete =j.key();
////        if(class_to_delete.getLesson() != lesson.getLesson())
////            this->this_term_classes.insert (j,j.key(),j.value());

////    }

////        auto &class_to_delete =i.key();
//////        this->this_term_classes.removeIf(,this_term_classes.end(),class_to_delete.getLesson() == lesson.getLesson());
////        if(class_to_delete.getLesson() ==lesson.getLesson()){
////            this->this_term_classes.erase(i.key()) ;

//}
void StudentMainMenu::registry(Class Class)
{
    Class.addStudent(this->get_username());

    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                Json::Value studentLessonsCopy = dataHolder[i]["terms"][Term - 1]["lessons"];

                Json::Value newLesson;

                newLesson["teacher"] = Class.getTeacher().toStdString();
                newLesson["lesson"] = lesson_enum_str[Class.getLesson()].toStdString();
                newLesson["score"] = -1;

                studentLessonsCopy.append(newLesson);

                dataHolder[i]["terms"][Term - 1]["lessons"] = studentLessonsCopy;

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}

void StudentMainMenu::addTerm()
{
    Term++;

    avereges.push_back(-1);

    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                dataHolder[i]["count_of_terms"] = dataHolder[i]["count_of_terms"].asInt() + 1;

                Json::Value newTerm;

                newTerm["average"] = -1;
                newTerm["lessons"] = Json::arrayValue;

                dataHolder[i]["terms"].append(newTerm);

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}

void StudentMainMenu::unregistery(Class Class)
{
    if(Class.studentIsValid(this->get_username()))
    {
        Class.deleteStudent(this->get_username());

        ifstream ifs(filePath.toStdString());

        if(dataReader.parse(ifs, dataHolder))
        {
            for(int i = 0; i < dataHolder.size(); i++)
            {
                if(get_username().toStdString() == dataHolder[i]["username"].asString())
                {
                    Json::Value classesCopy = dataHolder[i]["terms"][Term - 1]["lessons"];

                    Json::Value wantedClasses;

                    for(int j = 0; j < classesCopy.size(); j++)
                    {
                        if(classesCopy[i]["lesson"].asString() != lesson_enum_str[Class.getLesson()].toStdString())
                            wantedClasses.append(classesCopy[i]);
                    }

                    dataHolder[i]["terms"][Term - 1]["lessons"] = wantedClasses;

                    ofstream ofs(filePath.toStdString());

                    Json::StyledWriter writer;

                    string serializedData = writer.write(dataHolder);

                    ofs << serializedData;

                    ofs.close();

                    return;
                }
            }
        }
    }
}

void StudentMainMenu::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}

void StudentMainMenu::on_pushButton_clicked()
{
    StudentProfile* sp = new StudentProfile(this);
    sp->show();
    close();
}

void StudentMainMenu::load()
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        if(!createUserRecord()) return;

        for(auto& student : dataHolder)
        {
            if(get_username().toStdString() == student["username"].asString())
            {
                this->Term = student["count_of_terms"].asInt();

                if(!student["terms"].empty())
                {
                    this->currentAverege = student["terms"][Term - 1]["average"].asInt();
                }
                else
                {
                    this->currentAverege = -1;
                }

                for(auto& term : student["terms"])
                {
                    this->avereges.push_back(term["average"].asFloat());
                }

                return;
            }
        }
        return;
    }

    ofstream ofs(filePath.toStdString());

    Json::StyledWriter writer;

    Json::Value baseData;

    Json::Value baseStudent;

    baseStudent["username"] = get_username().toStdString();
    baseStudent["terms"] = Json::arrayValue;
    baseStudent["is_registering"] = false;
    baseStudent["count_of_terms"] = 0;

    this->Term = 0;

    this->currentAverege = -1;

    baseData.append(baseStudent);

    string serializedData = writer.write(baseData);

    ofs << serializedData;

    ofs.close();
}

bool StudentMainMenu::createUserRecord()
{
    for(int i = 0; i < dataHolder.size(); i++)
    {
        if(get_username().toStdString() == dataHolder[i]["username"].asString())
            return true;
    }

    Json::Value newStudentRecord;

    newStudentRecord["username"] = get_username().toStdString();
    newStudentRecord["terms"] = Json::arrayValue;
    newStudentRecord["count_of_terms"] = 0;
    newStudentRecord["is_registering"] = false;

    this->Term = 0;

    this->currentAverege = -1;

    dataHolder.append(newStudentRecord);

    ofstream ofs(filePath.toStdString());

    Json::StyledWriter writer;

    string serializedData = writer.write(dataHolder);

    ofs << serializedData;

    ofs.close();

    return false;
}


void StudentMainMenu::finalizeRegistering()
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                dataHolder[i]["is_registering"] = false;

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}

bool StudentMainMenu::canRegister()
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(auto& student : dataHolder)
        {
            if(get_username().toStdString() == student["username"].asString())
            {
                return student["is_registering"].asBool();
            }
        }
    }

    return false;
}

QList<QMap<QString, QString>> StudentMainMenu::getClasses(int chosenTerm)
{
    QList<QMap<QString, QString>> wantedInformation ;
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto i : this->dataHolder)
        {
            if(i["username"] == this->get_username().toStdString())
            {
                for(auto j : i["terms"][chosenTerm]["lessons"])
                {
                    QMap<QString , QString> holder;
                    holder["teacher"] = QString::fromStdString(j["teacher"].asString());
                    holder["score"] = QString::fromStdString(j["score"].asString());
                    holder["lesson"] = QString::fromStdString(j["lesson"].asString());
                    wantedInformation.push_back(holder);
                }
                return wantedInformation;
            }
        }


    }


}

int StudentMainMenu::getTerm()
{
    return this->Term;
}

// json sturcture of each student
//
//{
//    "username": 65564,
//        "terms": [
//            {
//                "average": 5564,
//                "lesson": [
//                    {
//                        "teacher": "dsf",
//                        "score": 545.6565,
//                        "lesson": "gosasteh"
//                    }
//    ]
//            },
//            {
//                "average": -1,
//                "lessons": [
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    }
//                ]
//            }
//        ]
//}



void StudentMainMenu::on_pushButton_2_clicked()
{
    studentMessages * stm = new studentMessages(this) ;
    stm->show();
    close();
}


void StudentMainMenu::on_pushButton_3_clicked()
{
    studentWeeklySchedule * sws = new studentWeeklySchedule(this);

    sws->show();

    close();
}

void StudentMainMenu::on_pushButton_4_clicked()
{
    bool canRegister = this->canRegister();

    if(!canRegister)
    {
        QMessageBox* alreadyRegistered = new QMessageBox(
            QMessageBox::Warning,
            "Already Registered",
            "you finalized registering for term."
        );

        alreadyRegistered->show();

        connect(alreadyRegistered, &QMessageBox::buttonClicked, alreadyRegistered, &QMessageBox::deleteLater);

        return;
    }

    this->addTerm();

    StudentEnrolment * sem = new StudentEnrolment(this);

    sem->show();

    this->close();
}

void StudentMainMenu::on_pushButton_6_clicked()
{
    StudentTerms* st = new StudentTerms(this);
    st->show();
    close();
}



void StudentMainMenu::on_pushButton_7_clicked()
{
    StudentTeacherSurvey* sts = new StudentTeacherSurvey(this);
    sts->show();
    close();
}



