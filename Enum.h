#ifndef ENUM_H
#define ENUM_H

#include <QString>

enum lesson {
    CHEMISTRY,
    BP,
    DISCRETE,
    CALCULUS,
    PHYSICS
};

lesson string_to_lesson(QString lesson_str);

static QString lesson_enum_str[] =
        { "CHEMISTRY", "BP", "DISCRETE", "CALCULUS" , "PHYSICS"};

enum day{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

day string_to_day(QString day_str);


static QString day_enum_str[] =
        { "SATURDAY", "SUNDAY", "MONDAY", "TUESDAY" , "WEDNESDAY", "THURSDAY", "FRIDAY"};


//QString LessonToString ( int enum_val )
//{
//    QString tmp(lesson_enum_str[enum_val]);
//    return tmp;
//}

//QString DayToString ( int enum_val )
//{
//    QString tmp(day_enum_str[enum_val]);
//    return tmp;
//}


#endif // ENUM_H
