#ifndef ROSTEROBJECT_H
#define ROSTEROBJECT_H

#include <QObject>

#include "CodeStyle.h"

class RosterObject : public QObject
{
    Q_OBJECT
public:
    RosterObject(QObject *parent = 0);

    virtual bool isError() const;
    virtual QString lastError() const;
    virtual void clearError() const;

signals:
    void error(const QString &text) const;
    void message(const QString &text) const;
    void success(const QString &text) const;

protected:
    virtual void logError(const QString &text) const;
    virtual void logMessage(const QString &text) const;
    virtual void logSuccess(const QString &text) const;

protected slots:
    virtual bool postError(const QString &text) const;
    virtual void postMessage(const QString &text) const;
    virtual bool postSuccess(const QString &text = QString()) const;

protected:
    // Mutable for clearError function
    mutable QString m_lastError;

};

#endif // ROSTEROBJECT_H
