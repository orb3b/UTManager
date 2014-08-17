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

# *********** Deploy ************
DLLDESTDIR += $$BIN \
              $$APPLICATION_TESTS_BIN \
              $$ROSTER_TESTS_BIN

# *********** Source ************
SOURCES += *.cpp
HEADERS += *.h \
    RosterCommon.h
