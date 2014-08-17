# Include checking
!contains(INCLUDED_PRI, $$PWD/Defaults.pri) {
INCLUDED_PRI += $$PWD/Defaults.pri

# ######### Defaults.pri ########

# Paths
ROOT = "$$PWD/.."

BIN = $$ROOT/bin
LIB = $$ROOT/lib
SRC = $$ROOT/src

TESTS = $$ROOT/tests

# Codestyle dependencies
INCLUDEPATH += $$SRC/Common

# ###############################

}
# End Include checking
