#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T17:04:45
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_pawn
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH +=  "$$PWD/../../../../../../src" \
                "$$PWD/../../../UT99CampaignRoster/Roster"

DLLDESTDIR = "$$PWD\..\..\..\..\tests\Roster"

SOURCES += tst_pawn.cpp \
    ../../../UT99CampaignRoster/Roster/Pawn.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../../UT99CampaignRoster/Roster/Pawn.h
