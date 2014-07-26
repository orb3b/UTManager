#include "MaterialCollection.h"

#include "ClassCollection.h"

MaterialCollection::MaterialCollection(QObject *parent) :
    RosterObject(parent)
{
    createClassCollection();
}

MaterialCollection::~MaterialCollection()
{    
    deleteClassCollection();
}

ClassCollection *MaterialCollection::classCollection()
{
    return m_classCollection;
}

void MaterialCollection::createClassCollection()
{
    deleteClassCollection();

    m_classCollection = new ClassCollection();
    connect(m_classCollection, SIGNAL(destroyed(QObject*)), SLOT(onMemberDestroyed(QObject*)));
}

void MaterialCollection::deleteClassCollection()
{
    if (!m_classCollection)
        return;

    disconnect(m_classCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));

    delete m_classCollection;
    m_classCollection = nullptr;
}

void MaterialCollection::onMemberDestroyed(QObject *obj)
{
    if (obj == m_classCollection) {
        m_classCollection = nullptr;
        postError("Class collection have been destroyed externally, going to recreate it");
        createClassCollection();
        return;
    }
}
