#-------------------------------------------------
#
# Include this file to link Roster library to project
# Setup ROSTER_DEPLOYDIR variable BEFORE including this file
# to deploy roster to specified directory
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

# ************ Roster Deploy ***********
!isEmpty(ROSTER_DEPLOYDIR) {
QMAKE_POST_LINK += "copy /y \"$$ROSTER_DESTDIR\\$$ROSTER_TARGET.dll\" \"$$ROSTER_DEPLOYDIR\\$$ROSTER_TARGET.dll\""
}

# ######################################

}
# End Include checking
