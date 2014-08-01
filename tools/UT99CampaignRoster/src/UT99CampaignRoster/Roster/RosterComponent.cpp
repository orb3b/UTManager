#include "RosterComponent.h"

#include "Logs.h"

RosterComponent::RosterComponent()
{
}

bool RosterComponent::isError() const
{
    return !m_lastError.isEmpty();
}

QString RosterComponent::lastError() const
{
    return m_lastError;
}

void RosterComponent::clearError() const
{
    m_lastError.clear();
}

bool RosterComponent::isConsistent() const
{
    return true;
}

void RosterComponent::notifyError(const QString & /*text*/) const
{
    // No op - all work will be done it subclasses
}

void RosterComponent::notifyWarning(const QString & /*text*/) const
{
    // No op - all work will be done it subclasses
}

void RosterComponent::notifyMessage(const QString & /*text*/) const
{
    // No op - all work will be done it subclasses
}

void RosterComponent::notifySuccess(const QString & /*text*/) const
{
    // No op - all work will be done it subclasses
}

void RosterComponent::logError(const QString &text) const
{
    sLogErr << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

void RosterComponent::logWarning(const QString &text) const
{
    sLogWrn << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

void RosterComponent::logMessage(const QString &text) const
{
    sLogDbg << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

void RosterComponent::logSuccess(const QString &text) const
{
    sLogMsg << QString("[%1] %2").arg(_CLASS_NAME_, text);
}

bool RosterComponent::postError(const QString &text) const
{
    m_lastError = text;

    logError(text);

    notifyError(text);

    return false;
}

void RosterComponent::postWarning(const QString &text) const
{
    logWarning(text);

    notifyWarning(text);
}

void RosterComponent::postMessage(const QString &text) const
{
    logMessage(text);

    notifyMessage(text);
}

bool RosterComponent::postSuccess(const QString &text) const
{
    clearError();

    logSuccess(text);

    notifySuccess(text);

    return true;
}
