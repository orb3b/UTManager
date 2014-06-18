#ifndef ROSTEROBJECT_H
#define ROSTEROBJECT_H

#include <QObject>

#define OWNERSHIP

class RosterObject : public QObject
{
    Q_OBJECT
public:
    RosterObject(QObject *parent = 0);

    virtual bool isError();
    virtual QString lastError();

signals:
    void error(const QString &text);
    void message(const QString &text);
    void success(const QString &text);

protected slots:
    virtual bool postError(const QString &text);
    virtual void postMessage(const QString &text);
    virtual bool postSuccess(const QString &text = QString());

protected:
    QString m_lastError;

};

#endif // ROSTEROBJECT_H
