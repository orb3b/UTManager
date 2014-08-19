TEMPLATE = subdirs

SUBDIRS += \
           Core \
           Tests \
           UT99CampaignRoster

UT99CampaignRoster.depends += \
    Core

Tests.depends += \
    UT99CampaignRoster
