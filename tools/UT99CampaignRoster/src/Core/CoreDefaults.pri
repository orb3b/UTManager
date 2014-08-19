# Include checking
!contains(INCLUDED_PRI, $$PWD/CoreDefaults.pri) {
INCLUDED_PRI += $$PWD/CoreDefaults.pri

# ######## CoreDefaults.pri ######

!include( $$PWD/../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# Roster Variables
CORE_TARGET = Core
CORE_DESTDIR = $$LIB/$$CORE_TARGET 

# ###############################

}
# End Include checking

