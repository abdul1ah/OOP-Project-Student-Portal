QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminpannel.cpp \
    globalvariables.cpp \
    main.cpp \
    mainwindow.cpp \
    studentlogin.cpp \
    studentpannel.cpp \
    teacherlogin.cpp \
    teacherpannel.cpp \
    user.cpp

HEADERS += \
    adminlogin.h \
    adminpannel.h \
    globalvariables.h \
    mainwindow.h \
    studentlogin.h \
    studentpannel.h \
    teacherlogin.h \
    teacherpannel.h \
    user.h

FORMS += \
    adminlogin.ui \
    adminpannel.ui \
    mainwindow.ui \
    studentlogin.ui \
    studentpannel.ui \
    teacherlogin.ui \
    teacherpannel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Logos.qrc
