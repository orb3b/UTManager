#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T19:08:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UT99CampaignRoster
TEMPLATE = app

INCLUDEPATH += "$$PWD"


SOURCES += main.cpp\
        MainWindow.cpp \
    Roster/Roster.cpp \
    Roster/PawnCollection.cpp \
    Roster/RosterObject.cpp \
    Roster/PawnGroup.cpp \
    Roster/Pawn.cpp \
    Roster/TeamCollection.cpp

HEADERS  += MainWindow.h \
    Logs.h \
    Roster/Roster.h \
    Roster/PawnCollection.h \
    Roster/RosterObject.h \
    Roster/PawnGroup.h \
    Roster/Pawn.h \
    Roster/TeamCollection.h

FORMS    += MainWindow.ui
