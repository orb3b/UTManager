#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T19:08:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UT99CampaignRoster
TEMPLATE = app

INCLUDEPATH += "$$PWD" \
               "$$PWD\..\..\src"


SOURCES += main.cpp\
        MainWindow.cpp \
    Roster/Roster.cpp \
    Roster/PawnCollection.cpp \
    Roster/RosterObject.cpp \
    Roster/PawnGroup.cpp \
    Roster/Pawn.cpp \
    Roster/TeamCollection.cpp \
    PawnEditor.cpp \
    PawnGroupsWidget.cpp \
    PawnConverter.cpp \
    Roster/RosterComponent.cpp \
    TeamMembersWidget.cpp \
    InteractionWidget.cpp \
    Roster/RosterCollection.cpp \
    Roster/ClassCollection.cpp \
    Roster/MaterialCollection.cpp

HEADERS  += MainWindow.h \
    Logs.h \
    Roster/Roster.h \
    Roster/PawnCollection.h \
    Roster/RosterObject.h \
    Roster/PawnGroup.h \
    Roster/Pawn.h \
    Roster/TeamCollection.h \
    ../../src/CodeStyle.h \
    PawnEditor.h \
    PawnGroupsWidget.h \
    PawnConverter.h \
    Roster/RosterComponent.h \
    TeamMembersWidget.h \
    InteractionWidget.h \
    Roster/RosterCollection.h \
    Roster/ClassCollection.h \
    Roster/MaterialCollection.h

FORMS    += MainWindow.ui \
    PawnEditor.ui \
    PawnGroupsWidget.ui \
    TeamMembersWidget.ui \
    InteractionWidget.ui

RESOURCES += \
    RosterResources.qrc
