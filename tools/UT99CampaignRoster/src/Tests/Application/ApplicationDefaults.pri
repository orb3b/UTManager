!include( $$PWD/../../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# Default include path for Roster Application tests
INCLUDEPATH += "$$SRC/UT99CampaignRoster/Application"

# Default outdir for Roster Application tests
DLLDESTDIR = "$$ROOT/tests/Application"
