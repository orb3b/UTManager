TEMPLATE = subdirs

SUBDIRS += \
           Roster \
           Application

Application.depends += \
    Roster
