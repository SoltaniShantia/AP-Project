#include "Enum.h"

lesson string_to_lesson(QString lesson_str)
{


            if(lesson_str=="BP" || lesson_str =="bp") return lesson::BP;
            else if(lesson_str=="CHEMISTRY" || lesson_str == "chemistry" || lesson_str == "Chemistry") return lesson::CHEMISTRY;
            else if(lesson_str=="DISCRETE" || lesson_str == "discrete" || lesson_str == "Discrete") return lesson::DISCRETE;
            else if(lesson_str=="CALCULUS" || lesson_str == "calculus" || lesson_str == "Calculus") return lesson::CALCULUS;
            else if (lesson_str == "PHYSICS" || lesson_str == "physics" ||  lesson_str == "Physics") return lesson::PHYSICS;

}

day string_to_day(QString day_str)
{
    if(day_str=="SATURDAY" || day_str=="Saturday" || day_str=="saturday") return day::SATURDAY;
    else if(day_str=="SUNDAY" || day_str=="Sunday"|| day_str=="sunday") return day::SUNDAY;
    else if(day_str=="MONDAY" || day_str=="Monday" || day_str=="monday") return day::MONDAY;
    else if(day_str=="TUESDAY" || day_str=="Tuesday" || day_str=="tuesday") return day::TUESDAY;
    else if(day_str=="WEDNESDAY" || day_str=="Wednesday" || day_str=="wednesday") return day::WEDNESDAY;
    else if(day_str=="THURSDAY" || day_str=="Thursday" || day_str=="thursday") return day::THURSDAY;
    else return day::FRIDAY;
}
