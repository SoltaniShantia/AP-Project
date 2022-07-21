QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    StudentWeeklyCalendar.cpp \
    teacherstudentsetscore.cpp \
    teacherclasssetscore.cpp \
    studentenrolment.cpp \
    studentteachersurvey.cpp \
    studentterms.cpp \
    studenttermscores.cpp \
    studentwatchsurvey.cpp \
    Notification.cpp \
    adminclassinfo.cpp \
    adminwatchstudent.cpp \
    teacherclassinfo.cpp \
    teacherwatchstudent.cpp \
    Md5Hash.cpp \
    adminaddclass.cpp \
    adminmessages.cpp \
    adminwatchmessagecomplitly.cpp \
    teacherwatchmessagecomplitly.cpp \
    teacherweeklyschedule.cpp \
    studentmessages.cpp \
    studentwatchmessagecomplitly.cpp \
    teachermessages.cpp \
    studentweeklyschedule.cpp \
    CalendarCreator.cpp \
    Class.cpp \
    Enum.cpp \
    Poll.cpp \
    UserType.cpp \
    adminaddpeople.cpp \
    adminsendassertion.cpp \
    teachersendassertion.cpp \
    Auth.cpp \
    Filemanager.cpp \
    Permission.cpp \
    TeacherWeeklyCalendar.cpp \
    WeeklyCalendar.cpp \
    adminprofile.cpp \
    User.cpp \
    adminmainmenu.cpp \
    enterenewpass.cpp \
    forgotpasspage.cpp \
    loginpage.cpp \
    main.cpp \
    dist/jsoncpp.cpp \
    studentmainmenu.cpp \
    studentprofile.cpp \
    teachermainmenu.cpp \
    teacherprofile.cpp \

HEADERS += \
    StudentWeeklyCalendar.h \
    teacherstudentsetscore.h \
    teacherclasssetscore.h \
    studentenrolment.h \
    studentteachersurvey.h \
    studentterms.h \
    studenttermscores.h \
    studentwatchsurvey.h \
    Notification.h \
    adminclassinfo.h \
    adminwatchstudent.h \
    teacherclassinfo.h \
    teacherwatchstudent.h \
    Md5Hash.h \
    adminaddclass.h \
    adminmessages.h \
    adminwatchmessagecomplitly.h \
    teacherweeklyschedule.h \
    teacherwatchmessagecomplitly.h \
    studentmessages.h \
    studentwatchmessagecomplitly.h \
    studentweeklyschedule.h \
    studentmessages.h \
    teachermessages.h \
    CalendarCreator.h \
    Class.h \
    Enum.h \
    Poll.h \
    UserType.h \
    adminaddpeople.h \
    adminsendassertion.h \
    teachersendassertion.h \
    Auth.h \
    Filemanager.h \
    Permission.h \
    TeacherWeeklyCalendar.h \
    WeeklyCalendar.h \
    adminprofile.h \
    User.h \
    adminmainmenu.h \
    enterenewpass.h \
    forgotpasspage.h \
    loginpage.h \
    dist/json/json.h \
    dist/json/json-forwards.h \
    studentmainmenu.h \
    studentprofile.h \
    teachermainmenu.h \
    teacherprofile.h

FORMS += \
    teacherstudentsetscore.ui \
    teacherclasssetscore.ui \
    studentenrolment.ui \
    studentteachersurvey.ui \
    studentterms.ui \
    studenttermscores.ui \
    studentwatchsurvey.ui \
    adminclassinfo.ui \
    adminwatchstudent.ui \
    teacherclassinfo.ui \
    teacherwatchstudent.ui \
    adminaddclass.ui \
    adminmessages.ui \
    adminwatchmessagecomplitly.ui \
    teacherwatchmessagecomplitly.ui \
    teacherweeklyschedule.ui \
    studentwatchmessagecomplitly.ui \
    studentweeklyschedule.ui \
    studentmessages.ui \
    teachermessages.ui \
    adminaddpeople.ui \
    adminsendassertion.ui \
    teachersendassertion.ui \
    adminmainmenu.ui \
    adminprofile.ui \
    enterenewpass.ui \
    forgotpasspage.ui \
    loginpage.ui \
    studentmainmenu.ui \
    studentprofile.ui \
    teachermainmenu.ui \
    teacherprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arrowIcon.qrc \
    classIcon.qrc \
    icon.qrc \
    pictures.qrc \
    second-icon.qrc \
    term-management-icon.qrc \
    third-icon-group.qrc \
    endIcon.qrc

DISTFILES += \
    scorecard.png
