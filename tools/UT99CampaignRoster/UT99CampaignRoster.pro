#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T19:08:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UT99CampaignRoster
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Roster/Roster.cpp \
    Roster/PawnCollection.cpp \
    Roster/RosterObject.cpp

HEADERS  += MainWindow.h \
    Logs.h \
    Roster/Roster.h \
    Roster/PawnCollection.h \
    Roster/RosterObject.h

FORMS    += MainWindow.ui
