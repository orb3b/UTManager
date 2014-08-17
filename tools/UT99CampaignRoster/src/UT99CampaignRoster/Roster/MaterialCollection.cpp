#include "MaterialCollection.h"

#include "ClassCollection.h"
#include "WeaponCollection.h"

MaterialCollection::MaterialCollection(QObject *parent) :
    RosterObject(parent),
    m_classCollection(new ClassCollection()),
    m_weaponCollection(new WeaponCollection())
{    
}

MaterialCollection::~MaterialCollection()
{    
}

bool MaterialCollection::isConsistent() const
{
    if (m_classCollection.isNull())
        return postError("Consistent breakdown: Class collection is null.");

    if (m_weaponCollection.isNull())
        return postError("Consistent breakdown: Weapon collection is null.");

    return true;
}

ClassCollection *MaterialCollection::classCollection()
{
    return m_classCollection.data();
}

WeaponCollection *MaterialCollection::weaponCollection()
{
    return m_weaponCollection.data();
}
