#include "UserType.h"


UserType strToUserType(QString userType)
{
    if(userType.toLower() == "admin")
        return UserType::ADMIN;
    else if(userType.toLower() == "teacher")
        return UserType::TEACHER;
    else
        return UserType::STUDENT;
}

QString userTypeToStr(UserType userType)
{
    if(userType == UserType::ADMIN)
        return "ADMIN";
    else if(userType == UserType::TEACHER)
        return "TEACHER";
    else
        return "STUDENT";
}
