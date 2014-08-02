#-------------------------------------------------
#
# Project created by QtCreator 2014-08-02T11:07:18
#
#-------------------------------------------------

!include( $$PWD/../RosterDefaults.pri ) {
    error("Couldn't find ../RosterDefaults.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_RosterDataProvider
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_RosterDataProvider.cpp \
    ../../../UT99CampaignRoster/Roster/ClassCollection.cpp \
    ../../../UT99CampaignRoster/Roster/FaceCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Material.cpp \
    ../../../UT99CampaignRoster/Roster/MaterialCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Pawn.cpp \
    ../../../UT99CampaignRoster/Roster/PawnClass.cpp \
    ../../../UT99CampaignRoster/Roster/PawnFace.cpp \
    ../../../UT99CampaignRoster/Roster/PawnSkin.cpp \
    ../../../UT99CampaignRoster/Roster/PawnVoice.cpp \
    ../../../UT99CampaignRoster/Roster/RosterComponent.cpp \
    ../../../UT99CampaignRoster/Roster/RosterContainer.cpp \
    ../../../UT99CampaignRoster/Roster/RosterDataProvider.cpp \
    ../../../UT99CampaignRoster/Roster/RosterObject.cpp \
    ../../../UT99CampaignRoster/Roster/SkinCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Weapon.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../../UT99CampaignRoster/Roster/ClassCollection.h \
    ../../../UT99CampaignRoster/Roster/FaceCollection.h \
    ../../../UT99CampaignRoster/Roster/Material.h \
    ../../../UT99CampaignRoster/Roster/MaterialCollection.h \
    ../../../UT99CampaignRoster/Roster/Pawn.h \
    ../../../UT99CampaignRoster/Roster/PawnClass.h \
    ../../../UT99CampaignRoster/Roster/PawnFace.h \
    ../../../UT99CampaignRoster/Roster/PawnSkin.h \
    ../../../UT99CampaignRoster/Roster/PawnVoice.h \
    ../../../UT99CampaignRoster/Roster/RosterComponent.h \
    ../../../UT99CampaignRoster/Roster/RosterContainer.h \
    ../../../UT99CampaignRoster/Roster/RosterDataProvider.h \
    ../../../UT99CampaignRoster/Roster/RosterObject.h \
    ../../../UT99CampaignRoster/Roster/SkinCollection.h \
    ../../../UT99CampaignRoster/Roster/Weapon.h
