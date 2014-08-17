#ifndef ROSTERCOMMON_H
#define ROSTERCOMMON_H

#include <QtGlobal>

// CodeStyle and common dependencies
#include <CodeStyle.h>
#include <Logs.h>

#if defined(ROSTER_LIB)
    #  define ROSTER_EXPORT Q_DECL_EXPORT
#else
    #  define ROSTER_EXPORT Q_DECL_IMPORT
#endif

#endif // ROSTERCOMMON_H
