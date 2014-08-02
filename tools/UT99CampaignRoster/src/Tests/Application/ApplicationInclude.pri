!include( $$PWD/ApplicationDefaults.pri ) {
    error("Couldn't find ApplicationDefaults.pri file!")
}

!include( $$PWD/ApplicationSources.pri ) {
    error("Couldn't find ApplicationSources.pri file!")
}
