!include( $$PWD/../Roster/RosterSources.pri ) {
    error("Couldn't find ../Roster/RosterSources.pri file!")
}

SOURCES += $$SRC/UT99CampaignRoster/Application/EditorConnector.cpp

HEADERS += \
    $$SRC/UT99CampaignRoster/Application/EditorConnector.h
