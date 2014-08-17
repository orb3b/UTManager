!include( RosterDefaults.pri ) {
    error("Couldn't find RosterDefaults.pri file!")
}

# ******** Project setup ********
TEMPLATE = lib
TARGET = $$ROSTER_TARGET
DEFINES += ROSTER_LIB

# ********* Dependencies ********
# Qt
QT += core

# *********** Output ************
DESTDIR = $$ROSTER_DESTDIR

# *********** Source ************
SOURCES += *.cpp
HEADERS += *.h \
    RosterCommon.h
