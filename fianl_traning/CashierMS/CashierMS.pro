#-------------------------------------------------
#
# Project created by QtCreator 2018-07-04T20:08:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CashierMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    cashierdialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    cashierdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    cashierdialog.ui

QT+=sql

INCLUDEPATH += "C:\Program Files\MySQL\MySQL Server 8.0\include"

LIBS += "C:\Program Files\MySQL\MySQL Server 8.0\lib\libmysql.lib"
