!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# ********* Dependencies ********
# Roster
INCLUDEPATH += "$$SRC/UT99CampaignRoster/Roster"


INCLUDEPATH += $$PWD/../Roster
LIBS += -L"$$ROSTER_LIB"
LIBS += -lRoster

# *********** Output ************
# Default outdir for Roster tests
DLLDESTDIR = "$$ROOT/tests/Roster"

