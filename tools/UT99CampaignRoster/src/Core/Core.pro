#-------------------------------------------------
#
# Core library
#
#-------------------------------------------------

!include( CoreDefaults.pri ) {
    error("Couldn't find CoreDefaults.pri file!")
}

# ******** Project setup ********
TEMPLATE = lib
TARGET = $$CORE_TARGET
DEFINES += CORE_LIBRARY

# ********* Dependencies ********
# Qt
QT += core

# *********** Output ************
DESTDIR = $$CORE_DESTDIR

# *********** Deploy ************
DLLDESTDIR += $$BIN

# *********** Source ************
SOURCES += *.cpp
HEADERS += *.h
