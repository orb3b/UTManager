#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T17:08:55
#
#-------------------------------------------------

!include( $$PWD/../ApplicationTestDefaults.pri ) {
    error("Couldn't find ../ApplicationTestDefaults.pri file!")
}

QT       += widgets testlib

TARGET = tst_editorConnector
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_editorConnector.cpp \
    $$PWD/../../../UT99CampaignRoster/Application/EditorConnector.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    $$PWD/../../../UT99CampaignRoster/Application/EditorConnector.h
