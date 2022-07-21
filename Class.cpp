#include "Class.h"
#include <iterator>
#include <fstream>
#include <string>
#include<iostream>
using namespace std;

Class::Class(enum lesson lesson, QString teacher)
{
    this->number_of_students = 0;
    this->lesson = lesson;
    this->teacher = teacher;
    this->filePath = "../data_resources/" + lesson_enum_str[lesson] + '-' + teacher +".json";

    ifstream ifs(filePath.toStdString());

    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->lesson = lesson;
        this->teacher = teacher;
        this->number_of_students = this->dataHolder["number_of_students"].asInt();
        this->location = QString::fromStdString( this->dataHolder["location"].asString());
        this->time = QString::fromStdString( this->dataHolder["time"].asString());
        this->day = string_to_day(QString::fromStdString( this->dataHolder["day"].asString()));

        for(int i = 0; i < dataHolder["student_list"].size(); i++){
            this->studentslist.insert(
                 QString::fromStdString(this->dataHolder["student_list"][i]["username"].asString()),
                 this->dataHolder["student_list"][i]["score"].asFloat()
            );
        }

    ifs.close();
    return;
    }


    ofstream ofs(filePath.toStdString());
    Json::StyledWriter writer;

    Json::Value baseData;
    baseData["teacher"] = teacher.toStdString();
    baseData["lesson"] = lesson_enum_str[lesson].toStdString();
    baseData["student_list"] = Json::arrayValue;

    string serializedData = writer.write(baseData);
    ofs << serializedData;
    ofs.close();
}

Class::Class(const Class &other)
{

    this->lesson = other.lesson;
    this->teacher = other.teacher;
    this->number_of_students = other.number_of_students;
    this->location = other.location;
    this->time = other.time;
    this->day = other.day;
    this->filePath = other.filePath;

    for(auto i = other.studentslist.begin();i!= other.studentslist.end(); i++){
        this->studentslist.insert(i.key(), i.value());
    }
}

void Class::setLocation(QString loc)
{
    this->location = loc;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["location"] = loc.toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }


}

void Class::setTime(QString time)
{
    this->time = time;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["time"] = time.toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }
}

void Class::setDay(enum day day)
{
    this->day = day;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["day"] = day_enum_str[day].toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }
}

void Class::addStudent(QString student_username)
{
    this->studentslist.insert(student_username, -1);
    this->number_of_students ++;
    ifstream ifs(this->filePath.toStdString());
    if (this->dataReader.parse(ifs , this->dataHolder))
    {
        this->dataHolder["number_of_students"] = this->dataHolder["number_of_students"].asInt() + 1 ;
        Json::Value newStudent ;
        newStudent["username"] = student_username.toStdString();
        newStudent["score"] =  -1;
        this->dataHolder["student_list"].append(newStudent);

        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer ;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart ;
        ofs.close();
    }
}

void Class::deleteStudent(QString student_username)
{
    this->studentslist.remove(student_username);
    this->number_of_students --;

    ifstream ifs(this->filePath.toStdString());
    if (this->dataReader.parse(ifs , this->dataHolder))
    {
        this->dataHolder["number_of_students"] = this->dataHolder["number_of_students"].asInt() - 1 ;
        Json::Value undeletedStudents;
        for(auto &i : this->dataHolder["student_list"])
        {
            if (student_username != QString::fromStdString(i["username"].asString()) )
            {
                undeletedStudents.append(i);
            }
        }
        this->dataHolder["student_list"] = undeletedStudents;


        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
    }




}

void Class:: setStudentScore(QString studentname,enum lesson lesson ,float newscore){

    Json::Value SdataHolder;
    Json::Reader SdataReader;
    ifstream ifs("../data_resources/student_term.json");

    if(SdataReader.parse(ifs, SdataHolder))
    {
        for(int i = 0; i < SdataHolder.size(); i++)
        {
            if(studentname.toStdString() == SdataHolder[i]["username"].asString())
            {
                int Term = SdataHolder[i]["count_of_terms"].asInt()-1;

                Json::Value classesCopy = SdataHolder[i]["terms"][Term]["lessons"];

                for(int j = 0; j < classesCopy.size(); j++)
                {
                    if(classesCopy[j]["lesson"].asString() == lesson_enum_str[lesson].toStdString())
                       classesCopy[j]["score"]=newscore;

                }


                SdataHolder[i]["terms"][Term]["lessons"] = classesCopy;
                if (SdataHolder[i]["terms"][Term]["average"].asFloat()==-1){
                    SdataHolder[i]["terms"][Term]["average"]=newscore;
                }
                else{
//                    SdataHolder[i]["terms"][Term]["average"]=(SdataHolder[i]["terms"][Term]["average"].asFloat()+newscore)/2;
                    int lsnCnt = 0;
                    float sum = 0;
                    for(int l = 0; l < (SdataHolder[i]["terms"][Term]["lessons"].size()); l++){
                        if (SdataHolder[i]["terms"][Term]["lessons"][l]["score"].asFloat()!=-1){
                            sum += SdataHolder[i]["terms"][Term]["lessons"][l]["score"].asFloat();
                            lsnCnt ++;
                        }
                    }
                    SdataHolder[i]["terms"][Term]["average"]= sum/lsnCnt;

                }

                ofstream ofs("../data_resources/student_term.json");

                Json::StyledWriter writer;

                string serializedData = writer.write(SdataHolder);

                ofs << serializedData;

                ofs.close();

                return;
            }
        }
    }
}


void Class::setScore(QString student_username, float score)
{
    for(auto i = this->studentslist.begin() ; i != this->studentslist.end(); i++){
        if(i.key()==student_username){
            i.value()=score;
        }
    }

    ifstream ifs (this->filePath.toStdString());

    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(int i = 0 ; i < this->dataHolder["student_list"].size() ; i++)
        {
            if(QString::fromStdString(this->dataHolder["student_list"][i]["username"].asString()) == student_username)
                this->dataHolder["student_list"][i]["score"] = score;
        }

        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter wrieter;

        string finalPart = wrieter.write(this->dataHolder);

        ofs << finalPart;
        ofs.close();
    }

    setStudentScore(student_username,this->getLesson(), score);
}

bool Class::studentIsValid(QString studentUsername)
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto i : this->dataHolder["student_list"] )
        {
            if(QString::fromStdString(i["username"].asString()) == studentUsername)
                return true;
        }
        return false;
    }

}

void Class::setinformation(enum lesson lesson, QString location, QString time, enum day day, QMap<QString , float> students)
{
    this->filePath = "../data_resources/" + lesson_enum_str[lesson] + '-' + this->getTeacher() +".json" ;
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        this->dataHolder["lesson"] = lesson_enum_str[lesson].toStdString();
        this->dataHolder["location"] = location.toStdString();
        this->dataHolder["time"] = time.toStdString();
        this->dataHolder["day"] = day_enum_str[day].toStdString();
        for(auto student =  students.begin() ; student != students.end() ; student++)
        {
            Json::Value usernmeKey;
            usernmeKey["username"] = student.key().toStdString();
            usernmeKey["score"] = student.value();
            this->dataHolder["student_list"].append(usernmeKey);
            if(this->number_of_students < 1 )
                this->number_of_students = 0 ;
            this->number_of_students++;
        }
        this->dataHolder["number_of_students"] = this->number_of_students;

        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart ;
        ofs.close();
    }

}

//void Class::addSurveyResult(QString student_username, int result)
//{
//    this->surveyresult.insert(student_username, result);
//}

lesson Class::getLesson()
{
    return this->lesson;
}

QString Class::getTeacher()
{
    return this->teacher;
}

QString Class::getLocation()
{
    return this->location;
}

QString Class::getTime()
{
    return this->time;
}

day Class::getDay()
{
    return this-> day;
}

int Class::getStudentNum()
{
    return this->number_of_students;
}

QMap<QString, float> Class::getList()
{
    return this->studentslist;
}

//QMap<QString, int> Class::getSurveyResult()
//{
//return this->surveyresult;
//}
