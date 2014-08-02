#include "MaterialCollection.h"

#include "ClassCollection.h"

MaterialCollection::MaterialCollection(QObject *parent) :
    RosterObject(parent),
    m_classCollection(new ClassCollection())
{    
}

MaterialCollection::~MaterialCollection()
{    
}

bool MaterialCollection::isConsistent() const
{
    if (m_classCollection.isNull())
        return postError("Consistent breakdown: Class collection is null.");

    return true;
}

ClassCollection *MaterialCollection::classCollection()
{
    return m_classCollection.data();
}
