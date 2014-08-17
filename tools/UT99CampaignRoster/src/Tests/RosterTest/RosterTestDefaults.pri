!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# ********* Dependencies ********
!include( $$SRC_CODE/Roster/RosterInclude.pri) {
    error("Couldn't find $$SRC_CODE/Roster/RosterInclude.pri file!")
}
# *********** Output ************
DLLDESTDIR = $$ROSTER_TESTS_BIN

