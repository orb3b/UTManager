#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T17:04:45
#
#-------------------------------------------------

!include( $$PWD/../RosterTestDefaults.pri ) {
    error("Couldn't find ../RosterTestDefaults.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_pawn
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_pawn.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
