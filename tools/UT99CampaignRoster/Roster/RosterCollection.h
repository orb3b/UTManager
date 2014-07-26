#ifndef ROSTERCOLLECTION_H
#define ROSTERCOLLECTION_H

#include "RosterObject.h"

#include <QList>
#include <QObject>

template<class T>
class RosterCollection : public RosterComponent
{
public:
    explicit RosterCollection(QObject *derived);
    ~RosterCollection();

    void clear();
    void size() const;
    void isEmpty() const;

    // Adds member to collection
    virtual bool addMember(OWNERSHIP T *member);
    // Removes member under key from collection, return false if member aren't exist
    virtual bool removeMember(T *member);
    // NOTE: You can also delete particular member via delete operator

    // Returns first member in collection
    T *first() const;
    // Return all members in collection
    QList<T *> all() const;

protected:

protected:
    virtual void onMemberDestroyed(QObject *obj);

protected:
    QList<T *> m_memberList;
    QObject *m_derived;
};

#endif // ROSTERCOLLECTION_H
