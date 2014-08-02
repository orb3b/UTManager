#include "RosterDataProvider.h"


#include "MaterialCollection.h"

RosterDataProvider::RosterDataProvider(QObject *parent) :
    RosterObject(parent)
{
}

bool RosterDataProvider::isConsistent() const
{
    if (m_materialCollection.isNull())
        return false;

    return true;
}

QString RosterDataProvider::path() const
{
    return m_path;
}

void RosterDataProvider::setPath(const QString &newPath)
{
    m_path = newPath;
}

void RosterDataProvider::setMaterialCollection(MaterialCollection *collection)
{
    m_materialCollection = collection;
}

bool RosterDataProvider::load()
{
    return true;
}
