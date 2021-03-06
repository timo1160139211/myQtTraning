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
    cashierdialog.cpp \
    connectionpool.cpp \
    usermodel.cpp \
    purchasedialog.cpp \
    memberadd.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    cashierdialog.h \
    connectionpool.h \
    initdatabase.h \
    usermodel.h \
    purchasedialog.h \
    memberadd.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    cashierdialog.ui \
    purchasedialog.ui \
    memberadd.ui

QT+=sql

INCLUDEPATH += "C:/mysql_backup_old/MySQL/include"

LIBS += "C:/mysql_backup_old/MySQL/lib/libmysql.lib"
#LIBS += -LC:/mysql_backup_old/MySQL/lib \
#    -lmysql
