#-------------------------------------------------
#
# Include this file to link Roster library to project
#
#-------------------------------------------------

# Include checking
!contains(INCLUDED_PRI, $$PWD/CoreInclude.pri) {
INCLUDED_PRI += $$PWD/CoreInclude.pri

# ######### IncludeRoster.pri ##########

!include( CoreDefaults.pri ) {
    error("Couldn't find CoreDefaults.pri file!")
}

# ********* Roster Dependencies ********
INCLUDEPATH += $$SRC/Core
LIBS += -L"$$CORE_DESTDIR"
LIBS += -l"$$CORE_TARGET"

# ######################################

}
# End Include checking
