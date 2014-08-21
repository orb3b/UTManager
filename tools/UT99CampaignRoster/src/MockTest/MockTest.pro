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

LIBS += -L"$$DEP_LIB/gtest" \
        -L"$$DEP_LIB/gmock"


CONFIG(debug, debug|release){
    LIBS += -lgtestd
    LIBS += -lgmockd
}

CONFIG(release, debug|release){
    LIBS += -lgtest
    LIBS += -lgmock
}

TEMPLATE = app

DLLDESTDIR += $$BIN

SOURCES += tst_mocktest.cpp \
    main.cpp \
    Turtle.cpp \
    MockTurtle.cpp \
    Painter.cpp \
    tst_Painter.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    Turtle.h \
    MockTurtle.h \
    Painter.h
