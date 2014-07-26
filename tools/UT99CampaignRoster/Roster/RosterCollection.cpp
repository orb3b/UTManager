#include "RosterCollection.h"

template<class T>
RosterCollection<T>::RosterCollection(QObject *derived) :
    RosterComponent(),
    m_derived(derived)
{

}

template<class T>
RosterCollection<T>::~RosterCollection()
{
    clear();
}

template<class T>
void RosterCollection<T>::clear()
{
    clearError();

    foreach (T *obj, m_memberList) {
        disconnect(obj, SIGNAL(destroyed(QObject*)), this, SLOT(onObjectDestroyed(QObject*)));
        delete obj;
    }

    m_memberList.clear();
}

template<class T>
void RosterCollection<T>::size() const
{
    clearError();

    return m_memberList.size();
}

template<class T>
void RosterCollection<T>::isEmpty() const
{
    clearError();

    return m_memberList.isEmpty();
}

template<class T>
bool RosterCollection<T>::addMember(T *member)
{
    // Currently its's simple adding, no sorting

    clearError();

    if (!member)
        return postError("Can't add null member to collection");

    connect(member, SIGNAL(destroyed(QObject*)), SLOT(onObjectDestroyed(QObject*)));

    m_memberList.append(member);

    return true;
}

template<class T>
bool RosterCollection<T>::removeMember(T *member)
{
    clearError();

    if (!m_memberList.contains(member))
        return postError("Can't remove member which don't exist in collection");

    disconnect(member, SIGNAL(destroyed(QObject*)), this, SLOT(onObjectDestroyed(QObject*)));

    delete member;

    m_memberList.removeAll(member);

    return true;
}

template<class T>
T *RosterCollection<T>::first() const
{
    clearError();

    if (m_memberList.isEmpty())
        return nullptr;

    return m_memberList.first();
}

template<class T>
QList<T *> RosterCollection<T>::all() const
{
    clearError();

    return m_memberList;
}

template<class T>
void RosterCollection<T>::onMemberDestroyed(QObject *obj)
{
    m_memberList.removeAll(obj);
}
