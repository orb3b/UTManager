#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T17:08:55
#
#-------------------------------------------------

!include( $$PWD/../ApplicationDefaults.pri ) {
    error("Couldn't find ../ApplicationDefaults.pri file!")
}

QT       += widgets testlib

TARGET = tst_editorConnector
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_editorConnector.cpp \
    ../../../UT99CampaignRoster/EditorConnector.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../../UT99CampaignRoster/EditorConnector.h
