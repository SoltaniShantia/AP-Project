QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminaddclass.cpp \
    adminaddpeople.cpp \
    adminclassinfo.cpp \
    adminmainmenu.cpp \
    adminmessages.cpp \
    adminprofile.cpp \
    adminsendassertion.cpp \
    adminwatchmessagecomplitly.cpp \
    adminwatchstudent.cpp \
    enterenewpass.cpp \
    forgotpasspage.cpp \
    loginpage.cpp \
    main.cpp \
    studentmainmenu.cpp \
    studentmessages.cpp \
    studentprofile.cpp \
    studentwatchmessagecomplitly.cpp \
    studentweeklyschedule.cpp \
    teacherclassinfo.cpp \
    teachermainmenu.cpp \
    teachermessages.cpp \
    teacherprofile.cpp \
    teachersendassertion.cpp \
    teacherwatchmessagecomplitly.cpp \
    teacherwatchstudent.cpp \
    teacherweeklyschedule.cpp

HEADERS += \
    adminaddclass.h \
    adminaddpeople.h \
    adminclassinfo.h \
    adminmainmenu.h \
    adminmessages.h \
    adminprofile.h \
    adminsendassertion.h \
    adminwatchmessagecomplitly.h \
    adminwatchstudent.h \
    enterenewpass.h \
    forgotpasspage.h \
    loginpage.h \
    studentmainmenu.h \
    studentmessages.h \
    studentprofile.h \
    studentwatchmessagecomplitly.h \
    studentweeklyschedule.h \
    teacherclassinfo.h \
    teachermainmenu.h \
    teachermessages.h \
    teacherprofile.h \
    teachersendassertion.h \
    teacherwatchmessagecomplitly.h \
    teacherwatchstudent.h \
    teacherweeklyschedule.h

FORMS += \
    adminaddclass.ui \
    adminaddpeople.ui \
    adminclassinfo.ui \
    adminmainmenu.ui \
    adminmessages.ui \
    adminprofile.ui \
    adminsendassertion.ui \
    adminwatchmessagecomplitly.ui \
    adminwatchstudent.ui \
    enterenewpass.ui \
    forgotpasspage.ui \
    loginpage.ui \
    studentmainmenu.ui \
    studentmessages.ui \
    studentprofile.ui \
    studentwatchmessagecomplitly.ui \
    studentweeklyschedule.ui \
    teacherclassinfo.ui \
    teachermainmenu.ui \
    teachermessages.ui \
    teacherprofile.ui \
    teachersendassertion.ui \
    teacherwatchmessagecomplitly.ui \
    teacherwatchstudent.ui \
    teacherweeklyschedule.ui

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
    third-icon-group.qrc

DISTFILES += \
    scorecard.png
