#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T19:08:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UT99CampaignRoster
TEMPLATE = app

DESTDIR += "$$PWD\..\..\bin"

INCLUDEPATH += "$$PWD" \
               "$$PWD\..\..\..\..\src"


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
    Roster/ClassCollection.cpp \
    Roster/MaterialCollection.cpp \
    Roster/RosterContainer.cpp \
    Roster/Material.cpp \
    Roster/PawnClass.cpp \
    Roster/SkinCollection.cpp \
    Roster/PawnSkin.cpp \
    Roster/FaceCollection.cpp \
    Roster/PawnFace.cpp

HEADERS  += MainWindow.h \
    Logs.h \
    Roster/Roster.h \
    Roster/PawnCollection.h \
    Roster/RosterObject.h \
    Roster/PawnGroup.h \
    Roster/Pawn.h \
    Roster/TeamCollection.h \
    ../../../../src/CodeStyle.h \
    PawnEditor.h \
    PawnGroupsWidget.h \
    PawnConverter.h \
    Roster/RosterComponent.h \
    TeamMembersWidget.h \
    InteractionWidget.h \
    Roster/ClassCollection.h \
    Roster/MaterialCollection.h \
    Roster/RosterContainer.h \
    Roster/Material.h \
    Roster/PawnClass.h \
    Roster/SkinCollection.h \
    Roster/PawnSkin.h \
    Roster/FaceCollection.h \
    Roster/PawnFace.h

FORMS    += MainWindow.ui \
    PawnEditor.ui \
    PawnGroupsWidget.ui \
    TeamMembersWidget.ui \
    InteractionWidget.ui

RESOURCES += \
    RosterResources.qrc
