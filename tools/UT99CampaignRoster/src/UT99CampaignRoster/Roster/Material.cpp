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

QString Material::description() const
{
    return m_description;
}

void Material::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}
