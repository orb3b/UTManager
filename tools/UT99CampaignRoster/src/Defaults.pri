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

DEP = $$ROOT/dep
DEP_INCLUDE = $$DEP/include
DEP_LIB = $$DEP/lib

LIB = $$ROOT/lib

SRC = $$ROOT/src
SRC_CODE = $$ROOT/src/UT99CampaignRoster

# Codestyle dependencies
INCLUDEPATH += $$SRC/Common

# ###############################

}
# End Include checking
