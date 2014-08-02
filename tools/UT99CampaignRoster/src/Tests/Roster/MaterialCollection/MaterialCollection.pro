#-------------------------------------------------
#
# Project created by QtCreator 2014-08-02T11:26:18
#
#-------------------------------------------------

!include( $$PWD/../RosterInclude.pri ) {
    error("Couldn't find ../RosterInclude.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_MaterialCollection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_MaterialCollection.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
