#-------------------------------------------------
#
# Project created by QtCreator 2021-05-10T23:21:42
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        main_server.cpp \
    mythread.cpp \
    myserver.cpp \
    database.cpp

HEADERS  += main_server.h \
    mythread.h \
    myserver.h \
    database.h

FORMS    += main_server.ui
