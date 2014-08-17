# Include checking
!contains(INCLUDED_PRI, $$PWD/RosterDefaults.pri) {
INCLUDED_PRI += $$PWD/RosterDefaults.pri

# ###### RosterDefaults.pri #####

!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# Roster Variables
ROSTER_TARGET = Roster
ROSTER_DESTDIR = $$LIB/$$ROSTER_TARGET

# ###############################

}
# End Include checking

