!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# *********** Variables *********
APPLICATION_TESTS_BIN = $$TESTS_BIN/Application

# ********* Dependencies ********
#Roster
ROSTER_DEPLOYDIR  = $$APPLICATION_TESTS_BIN
!include( $$SRC_CODE/Roster/RosterInclude.pri) {
    error("Couldn't find $$SRC_CODE/Roster/RosterInclude.pri file!")
}

# Application
INCLUDEPATH += "$$SRC_CODE/Application"

# *********** Output ************
DLLDESTDIR = $$APPLICATION_TESTS_BIN
