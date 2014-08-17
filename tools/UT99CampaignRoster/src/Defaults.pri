# Include checking
!contains(INCLUDED_PRI, $$PWD/Defaults.pri) {
INCLUDED_PRI += $$PWD/Defaults.pri

# ######### Defaults.pri ########

# Paths
ROOT = "$$PWD/.."

BIN = $$ROOT/bin
TESTS_BIN = $$ROOT/tests
APPLICATION_TESTS_BIN = $$TESTS_BIN/Application
ROSTER_TESTS_BIN = $$TESTS_BIN/Roster

LIB = $$ROOT/lib

SRC = $$ROOT/src
SRC_CODE = $$ROOT/src/UT99CampaignRoster

# Codestyle dependencies
INCLUDEPATH += $$SRC/Common

# ###############################

}
# End Include checking
