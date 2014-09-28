!include( $$PWD/../Defaults.pri ) {
    error("Couldn't find Defaults.pri file!")
}

# ********* Dependencies ********
# GTest & GMock
INCLUDEPATH += $$DEP_INCLUDE

LIBS += -L"$$DEP_LIB/gtest" \
        -L"$$DEP_LIB/gmock"


CONFIG(debug, debug|release){
    LIBS += -lgtestd
    LIBS += -lgmockd
}

CONFIG(release, debug|release){
    LIBS += -lgtest
    LIBS += -lgmock
}


