#ifndef ROSTERCOMPONENT_H
#define ROSTERCOMPONENT_H

#define VERIFY_CONSISTENCY(returnValue) \
do {\
    if (!isConsistent())\
        return returnValue;\
} while (0)

#define VERIFY_CONSISTENCY_VOID \
do {\
    if (!isConsistent())\
        return;\
} while (0)

#include "RosterGlobal.h"

class ROSTER_EXPORT RosterComponent
{
public:
    RosterComponent();

    virtual bool isError() const;
    virtual QString lastError() const;
    virtual void clearError() const;

    // Function for checking integrity for component
    // Can be used to check field shared by pointer
    virtual bool isConsistent() const;

protected:
    virtual void notifyError(const QString &text) const;
    virtual void notifyWarning(const QString &text) const;
    virtual void notifyMessage(const QString &text) const;
    virtual void notifySuccess(const QString &text) const;

    virtual void logError(const QString &text) const;
    virtual void logWarning(const QString &text) const;
    virtual void logMessage(const QString &text) const;
    virtual void logSuccess(const QString &text) const;

    virtual bool postError(const QString &text) const;
    virtual void postWarning(const QString &text) const;
    virtual void postMessage(const QString &text) const;
    virtual bool postSuccess(const QString &text = QString()) const;

protected:
    // Mutable for clearError function
    mutable QString m_lastError;

};

#endif // ROSTERCOMPONENT_H
