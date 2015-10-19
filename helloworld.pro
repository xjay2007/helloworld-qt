#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:45:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app

CONFIG   += console precompile_header
# Use Precompiled headers (PCH)
PRECOMPILED_HEADER = xmarcos.h

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    menuwindow.cpp \
    touchwidget.cpp \
    timerwidget.cpp

HEADERS  += xmarcos.h \
    mainwindow.h \
    logindialog.h \
    menuwindow.h \
    touchwidget.h \
    timerwidget.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    menuwindow.ui \
    touchwidget.ui \
    timerwidget.ui

RESOURCES += \
    resources.qrc
