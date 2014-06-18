#include "RosterObject.h"

#include "Logs.h"

RosterObject::RosterObject(QObject *parent) :
    QObject(parent)
{
}

bool RosterObject::isError()
{
    return !m_lastError.isEmpty();
}

QString RosterObject::lastError()
{
    return m_lastError;
}

bool RosterObject::postError(const QString &text)
{
    m_lastError = text;

    sLogErr << text;

    emit error(text);

    return false;
}

void RosterObject::postMessage(const QString &text)
{
    sLogDbg << text;

    emit message(text);
}

bool RosterObject::postSuccess(const QString &text)
{
    m_lastError.clear();

    sLogMsg << text;

    emit success(text);

    return true;
}
