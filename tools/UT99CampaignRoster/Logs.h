#ifndef LOGS_H
#define LOGS_H

#include <QtGlobal>
#include <QtDebug>

#define VERSION "1.0"

#define sLogDbg qDebug().nospace()
#define sLogMsg qWarning().nospace()
#define sLogErr qCritical().nospace()

#endif // LOGS_H
