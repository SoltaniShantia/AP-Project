#ifndef USERTYPE_H
#define USERTYPE_H

#include <QString>

enum UserType {
    ADMIN,
    TEACHER,
    STUDENT
};

UserType strToUserType(QString userType);
QString userTypeToStr(UserType userType);

#endif // USERTYPE_H
