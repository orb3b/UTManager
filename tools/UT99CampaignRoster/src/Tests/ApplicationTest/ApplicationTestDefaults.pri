!include( $$PWD/../TestDefaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# ********* Dependencies ********
#Roster
!include( $$SRC_CODE/Roster/RosterInclude.pri) {
    error("Couldn't find $$SRC_CODE/Roster/RosterInclude.pri file!")
}

# Application
INCLUDEPATH += "$$SRC_CODE/Application"

# *********** Output ************
DLLDESTDIR = $$APPLICATION_TESTS_BIN
