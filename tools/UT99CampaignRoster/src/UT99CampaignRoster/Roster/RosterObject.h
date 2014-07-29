#ifndef ROSTEROBJECT_H
#define ROSTEROBJECT_H

#include <QObject>
#include "RosterComponent.h"

class RosterObject : public QObject,
                     public RosterComponent
{
    Q_OBJECT
public:
    RosterObject(QObject *parent = 0);

signals:
    void error(const QString &text) const;
    void warning(const QString text) const;
    void message(const QString &text) const;
    void success(const QString &text) const;

protected:
    virtual void notifyError(const QString &text) const OVERWRITE;
    virtual void notifyWarning(const QString &text) const OVERWRITE;
    virtual void notifyMessage(const QString &text) const OVERWRITE;
    virtual void notifySuccess(const QString &text) const OVERWRITE;
};

#endif // ROSTEROBJECT_H
