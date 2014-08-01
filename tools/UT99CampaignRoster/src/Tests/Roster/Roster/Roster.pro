#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T18:20:20
#
#-------------------------------------------------

!include( $$PWD/../RosterDefaults.pri ) {
    error("Couldn't find ../RosterDefaults.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_roster
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_roster.cpp \
    ../../../UT99CampaignRoster/Roster/ClassCollection.cpp \
    ../../../UT99CampaignRoster/Roster/FaceCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Material.cpp \
    ../../../UT99CampaignRoster/Roster/MaterialCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Pawn.cpp \
    ../../../UT99CampaignRoster/Roster/PawnClass.cpp \
    ../../../UT99CampaignRoster/Roster/PawnCollection.cpp \
    ../../../UT99CampaignRoster/Roster/PawnFace.cpp \
    ../../../UT99CampaignRoster/Roster/PawnGroup.cpp \
    ../../../UT99CampaignRoster/Roster/PawnSkin.cpp \
    ../../../UT99CampaignRoster/Roster/PawnVoice.cpp \
    ../../../UT99CampaignRoster/Roster/Roster.cpp \
    ../../../UT99CampaignRoster/Roster/RosterComponent.cpp \
    ../../../UT99CampaignRoster/Roster/RosterContainer.cpp \
    ../../../UT99CampaignRoster/Roster/RosterObject.cpp \
    ../../../UT99CampaignRoster/Roster/SkinCollection.cpp \
    ../../../UT99CampaignRoster/Roster/TeamCollection.cpp \
    ../../../UT99CampaignRoster/Roster/Weapon.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../../UT99CampaignRoster/Roster/ClassCollection.h \
    ../../../UT99CampaignRoster/Roster/FaceCollection.h \
    ../../../UT99CampaignRoster/Roster/Material.h \
    ../../../UT99CampaignRoster/Roster/MaterialCollection.h \
    ../../../UT99CampaignRoster/Roster/Pawn.h \
    ../../../UT99CampaignRoster/Roster/PawnClass.h \
    ../../../UT99CampaignRoster/Roster/PawnCollection.h \
    ../../../UT99CampaignRoster/Roster/PawnFace.h \
    ../../../UT99CampaignRoster/Roster/PawnGroup.h \
    ../../../UT99CampaignRoster/Roster/PawnSkin.h \
    ../../../UT99CampaignRoster/Roster/PawnVoice.h \
    ../../../UT99CampaignRoster/Roster/Roster.h \
    ../../../UT99CampaignRoster/Roster/RosterComponent.h \
    ../../../UT99CampaignRoster/Roster/RosterContainer.h \
    ../../../UT99CampaignRoster/Roster/RosterObject.h \
    ../../../UT99CampaignRoster/Roster/SkinCollection.h \
    ../../../UT99CampaignRoster/Roster/TeamCollection.h \
    ../../../UT99CampaignRoster/Roster/Weapon.h
