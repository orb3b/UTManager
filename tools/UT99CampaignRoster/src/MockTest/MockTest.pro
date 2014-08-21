#-------------------------------------------------
#
# Project created by QtCreator 2014-08-20T16:56:38
#
#-------------------------------------------------

!include( $$PWD/../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

QT       += testlib

QT       -= gui

TARGET = tst_mocktest
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += $$DEP_INCLUDE

LIBS += -L"$$DEP_LIB/gtest"


CONFIG(debug, debug|release){
    LIBS += -lgtestd
}

CONFIG(release, debug|release){
    LIBS += -lgtest
}

TEMPLATE = app

DLLDESTDIR += $$BIN

SOURCES += tst_mocktest.cpp \
    main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
