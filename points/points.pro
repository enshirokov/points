#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T10:02:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = points
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    point.cpp \
    line.cpp

HEADERS  += mainwindow.h \
    view.h \
    point.h \
    line.h

FORMS    +=

RESOURCES += \
    images.qrc
