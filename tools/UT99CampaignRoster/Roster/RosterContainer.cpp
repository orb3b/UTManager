#include "RosterContainer.h"

RosterContainer::RosterContainer(QObject *parent) :
    RosterObject(parent)
{

}

RosterContainer::~RosterContainer()
{
    clearCollection();
}

void RosterContainer::clearCollection()
{
    clearError();

    foreach (RosterObject *obj, m_memberList) {
        disconnect(obj, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));
        delete obj;
    }

    m_memberList.clear();
}

bool RosterContainer::addMember(RosterObject *member)
{
    // Currently its's simple adding, no sorting

    clearError();

    if (!member)
        return postError("Can't add null member to collection");

    connect(member, SIGNAL(destroyed(QObject*)), SLOT(onMemberDestroyed(QObject*)));

    m_memberList.append(member);

    return true;
}

bool RosterContainer::removeMember(RosterObject *member)
{
    clearError();

    if (!m_memberList.contains(member))
        return postError("Can't remove member which don't exist in collection");

    disconnect(member, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));

    delete member;

    m_memberList.removeAll(member);

    return true;
}

QList<RosterObject *> &RosterContainer::data()
{
    return m_memberList;
}

const QList<RosterObject *> RosterContainer::data() const
{
    return m_memberList;
}

void RosterContainer::onMemberDestroyed(QObject *obj)
{
    m_memberList.removeAll(qobject_cast<RosterObject*>(obj));
}
