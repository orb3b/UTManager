#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T12:05:47
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_qstring
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


DLLDESTDIR = "$$PWD\..\..\..\..\tests\Roster"


SOURCES += tst_qstring.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
