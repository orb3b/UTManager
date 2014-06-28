#ifndef PAWNCOLLECTION_H
#define PAWNCOLLECTION_H

#include "RosterObject.h"

#include <QList>

class PawnGroup;

class PawnCollection : public RosterObject
{
    Q_OBJECT
public:
    PawnCollection(QObject *parent = 0);
    ~PawnCollection();

    bool open(const QString &path);

    PawnGroup *getGroup(const QString &groupName);
    bool addGroup(OWNERSHIP PawnGroup *group);

signals:
    void groupAdded(QString groupName);
    void groupRemoved(QString groupName);
    void groupChanged(QString groupName);

private:
    bool addGroupPrivate(OWNERSHIP PawnGroup *group);
    bool removeGroupPrivate(PawnGroup *group);

private slots:
    void onMemberGroupDestroyed(QObject *obj);

private:
    QList<PawnGroup *> m_groupList;

};

#endif // PAWNCOLLECTION_H
