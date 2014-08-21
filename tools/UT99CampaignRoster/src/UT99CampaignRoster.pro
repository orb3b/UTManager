TEMPLATE = subdirs

SUBDIRS += \
           Tests \
           UT99CampaignRoster \
    MockTest

Tests.depends += \
    UT99CampaignRoster
