#ifndef ROSTERCONTAINER_H
#define ROSTERCONTAINER_H

#include "RosterObject.h"

#include <QList>

class ROSTER_EXPORT RosterContainer : public RosterObject
{
public:
    explicit RosterContainer(QObject *parent = 0);
    ~RosterContainer();

    virtual void clearCollection();
    // Adds member to collection
    virtual bool addMember(OWNERSHIP RosterObject *member);
    // Removes member under key from collection, return false if member aren't exist
    virtual bool removeMember(RosterObject *member);
    // NOTE: You can also delete particular member via delete operator

    QList<RosterObject *> &data();
    const QList<RosterObject *> data() const;

protected slots:
    virtual void onMemberDestroyed(QObject *obj);

protected:
    QList<RosterObject *> m_memberList;
};

#endif // ROSTERCONTAINER_H
