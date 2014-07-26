#include "Material.h"

Material::Material(QObject *parent) :
    RosterObject(parent)
{
}

QString Material::name() const
{
    return m_name;
}

void Material::setName(const QString &newName)
{
    m_name = newName;
}
