#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T18:20:20
#
#-------------------------------------------------

!include( $$PWD/../RosterTestDefaults.pri ) {
    error("Couldn't find ../RosterTestDefaults.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_roster
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_roster.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

