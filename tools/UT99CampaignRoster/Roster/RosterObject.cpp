#include "RosterObject.h"

#include "Logs.h"

RosterObject::RosterObject(QObject *parent) :
    QObject(parent)
{
}

bool RosterObject::isError() const
{
    return !m_lastError.isEmpty();
}

QString RosterObject::lastError() const
{
    return m_lastError;
}

void RosterObject::clearError() const
{
    m_lastError.clear();
}

void RosterObject::logError(const QString &text) const
{
    sLogErr << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

void RosterObject::logMessage(const QString &text) const
{
    sLogDbg << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

void RosterObject::logSuccess(const QString &text) const
{
    sLogMsg << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

bool RosterObject::postError(const QString &text) const
{
    m_lastError = text;

    logError(text);

    emit error(text);

    return false;
}

void RosterObject::postMessage(const QString &text) const
{
    logMessage(text);

    emit message(text);
}

bool RosterObject::postSuccess(const QString &text) const
{
    clearError();

    logSuccess(text);

    emit success(text);

    return true;
}
