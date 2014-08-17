TEMPLATE = subdirs

SUBDIRS += \
           Tests \
           UT99CampaignRoster

Tests.depends += \
    UT99CampaignRoster
