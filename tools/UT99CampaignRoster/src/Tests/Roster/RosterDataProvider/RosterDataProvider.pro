#-------------------------------------------------
#
# Project created by QtCreator 2014-08-02T11:07:18
#
#-------------------------------------------------

!include( $$PWD/../RosterInclude.pri ) {
    error("Couldn't find ../RosterInclude.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_RosterDataProvider
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_RosterDataProvider.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
