#-------------------------------------------------
#
# Project created by QtCreator 2021-05-11T04:26:42
#
#-------------------------------------------------

QT       += core gui  network
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = order
TEMPLATE = app


SOURCES += main.cpp\
    registers.cpp \
    hotel.cpp \
    sign_in.cpp \
    user_mess.cpp \
    tcp.cpp \
    keyboard.cpp \
    repwdwin.cpp \
    bindid.cpp \
    rechargewin.cpp

HEADERS  += \
    registers.h \
    hotel.h \
    sign_in.h \
    user_mess.h \
    tcp.h \
    keyboard.h \
    repwdwin.h \
    bindid.h \
    rechargewin.h

FORMS    += \
    registers.ui \
    hotel.ui \
    sign_in.ui \
    user_mess.ui \
    tcp.ui \
    keyboard.ui \
    repwdwin.ui \
    bindid.ui \
    rechargewin.ui

RESOURCES += \
    img.qrc
