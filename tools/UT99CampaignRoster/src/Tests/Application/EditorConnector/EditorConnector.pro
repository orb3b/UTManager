#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T17:08:55
#
#-------------------------------------------------

!include( $$PWD/../ApplicationInclude.pri ) {
    error("Couldn't find ../ApplicationInclude.pri file!")
}

QT       += widgets testlib

TARGET = tst_editorConnector
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_editorConnector.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
