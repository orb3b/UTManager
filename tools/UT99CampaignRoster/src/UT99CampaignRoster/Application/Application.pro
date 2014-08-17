#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T19:08:55
#
#-------------------------------------------------

!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# ******** Project setup ********
TEMPLATE = app
TARGET = UT99CampaignRoster

# ********* Dependencies ********
# Qt
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Roster
ROSTER_DEPLOYDIR = $$BIN
!include( $$PWD/../Roster/RosterInclude.pri ) {
    error("Couldn't find RosterInclude.pri file!")
}

# *********** Output ************
DESTDIR = $$BIN


# *********** Source ************

SOURCES += *.cpp
HEADERS  += *.h

FORMS    += *.ui

RESOURCES += \
    RosterResources.qrc
