# Path to Root directory relative to Roster Application tests source
ROOT = "$$PWD/../../.."
SRC = $$ROOT/src

# Default include path for Roster Application tests
INCLUDEPATH +=  "$$ROOT/../../src" \
                "$$SRC/UT99CampaignRoster"

# Default outdir for Roster Application tests
DLLDESTDIR = "$$ROOT/tests/Application"
