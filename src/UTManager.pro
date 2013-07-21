#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T10:30:01
#
#-------------------------------------------------

QT       += core widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

###########################
###    SETUP VARS       ###
###########################

DEBUG_TARGET = UTManagerd
RELEASE_TARGET = UTManager

OUTDIR = ..

###########################
###    SETUP OUTPUT     ###
###########################
DESTDIR = $$OUTDIR\\bin

INCLUDEPATH += .

CONFIG(debug, debug|release){
    DEFINES += DEBUG
    TARGET = $$DEBUG_TARGET
}

CONFIG(release, debug|release){
    TARGET = $$RELEASE_TARGET
}

system(del $${DESTDIR}\\$${RELEASE_TARGET}.*)
system(del $${DESTDIR}\\$${DEBUG_TARGET}.*)

###########################
###       SOURCES       ###
###########################

SOURCES += main.cpp \
    View/MainView.cpp \
    View/ProjectView.cpp \
    Logger.cpp \
    View/LogView.cpp

HEADERS  += \
    View/MainView.h \
    View/ProjectView.h \
    Logger.h \
    View/LogView.h \
    define.h

FORMS    += \
    View/MainView.ui \
    View/ProjectView.ui \
    View/LogView.ui

RESOURCES += \
    resources.qrc
