#-------------------------------------------------
#
# Include this file to link Roster library to project
#
#-------------------------------------------------

# Include checking
!contains(INCLUDED_PRI, $$PWD/RosterInclude.pri) {
INCLUDED_PRI += $$PWD/RosterInclude.pri

# ######### IncludeRoster.pri ##########

!include( RosterDefaults.pri ) {
    error("Couldn't find RosterDefaults.pri file!")
}

# ********* Roster Dependencies ********
INCLUDEPATH += $$PWD
LIBS += -L"$$ROSTER_DESTDIR"
LIBS += -l"$$ROSTER_TARGET"

# ######################################

}
# End Include checking
