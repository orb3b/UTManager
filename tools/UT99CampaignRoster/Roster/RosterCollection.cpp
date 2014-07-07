#include "RosterCollection.h"

RosterCollection::RosterCollection(QObject *parent) :
    RosterObject(parent)
{
}

RosterCollection::~RosterCollection()
{
    clear();
}

void RosterCollection::clear()
{
    foreach (RosterObject *obj, m_objectList) {
        disconnect(obj, SIGNAL(destroyed(QObject*)), this, SLOT(onObjectDestroyed(QObject*)));
        delete obj;
    }

    m_objectList.clear();
}

int RosterCollection::size() const
{
    return m_objectList.size();
}

bool RosterCollection::addObjectPrivate(RosterObject *object)
{
    if (!object)
        return postError("Can't add null pointer roster object");

    connect(object, SIGNAL(destroyed(QObject*)), SLOT(onObjectDestroyed(QObject*)));

    m_objectList.append(object);

    return true;
}

void RosterCollection::onObjectDestroyed(QObject *obj)
{
    m_objectList.removeAll(obj);
}
