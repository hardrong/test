#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T23:17:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = caclulator
TEMPLATE = app


SOURCES += main.cpp\
        expr.cpp \
    model.cpp

HEADERS  += expr.h \
    model.h

FORMS    += expr.ui
