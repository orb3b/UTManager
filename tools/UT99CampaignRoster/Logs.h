#ifndef LOGS_H
#define LOGS_H

#include <QtGlobal>
#include <QtDebug>

#define VERSION "1.0"

#define sBaseLogDbg qDebug().nospace()
#define sBaseLogMsg qWarning().nospace()
#define sBaseLogErr qCritical().nospace()

#define sLogDbg (sBaseLogDbg << "[DEBUG][" << __FUNCTION__ << "]")
#define sLogMsg (sBaseLogMsg << "[MESSAGE]")
#define sLogErr (sBaseLogErr << "[ERROR]")


#endif // LOGS_H
