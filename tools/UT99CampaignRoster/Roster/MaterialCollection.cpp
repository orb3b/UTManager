#include "MaterialCollection.h"

MaterialCollection::MaterialCollection(QObject *parent) :
    RosterObject(parent),
    m_classCollection(nullptr)
{
}

MaterialCollection::~MaterialCollection()
{
    if (m_classCollection) {
        disconnect(m_classCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));
        delete m_classCollection;
        m_classCollection = nullptr;
    }
}

ClassCollection *MaterialCollection::classCollection()
{
    if (!m_classCollection) {
        m_classCollection = new PawnCollection();
        connect(m_classCollection, SIGNAL(destroyed(QObject*)), SLOT(onMemberDestroyed(QObject*)));
    }

    return m_classCollection;
}

void MaterialCollection::onMemberDestroyed(QObject *obj)
{
    if (obj == m_classCollection)
        m_classCollection = nullptr;
}
