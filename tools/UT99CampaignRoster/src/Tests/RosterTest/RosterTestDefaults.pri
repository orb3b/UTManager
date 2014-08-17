!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# *********** Variables *********
ROSTER_TESTS_BIN = $$TESTS_BIN/Roster

# ********* Dependencies ********
ROSTER_DEPLOYDIR  = $$ROSTER_TESTS_BIN
!include( $$SRC_CODE/Roster/RosterInclude.pri) {
    error("Couldn't find $$SRC_CODE/Roster/RosterInclude.pri file!")
}
# *********** Output ************
DLLDESTDIR = $$ROSTER_TESTS_BIN

