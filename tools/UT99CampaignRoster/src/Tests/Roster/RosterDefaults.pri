# Path to Root directory relative to Roster tests source
ROOT = "$$PWD/../../.."
SRC = $$ROOT/src

# Default include path for Roster tests
INCLUDEPATH +=  "$$ROOT/../../src" \
                "$$SRC/UT99CampaignRoster" \
                "$$SRC/UT99CampaignRoster/Roster"

# Default outdir for Roster tests
DLLDESTDIR = "$$ROOT/tests/Roster"

