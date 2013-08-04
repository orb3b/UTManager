#include "UTEntity.h"

#include <QImage>

UTEntity::UTEntity(QObject *parent) :
    m_settings(NULL),
    m_id(NULL),
    m_name(),
    m_pathToImage(),
    QObject(parent)
{
}

UTEntity::UTEntity(const UTEntity &entity)
{
    m_settings = entity.settings();
    m_id = entity.id();
    m_name = entity.name();
    m_pathToImage = entity.pathToImage();
    setParent(entity.parent());
}

UTEntity::UTEntity(const UTProjectSettings *settings, EntityID id, const QString &name, const QString &pathToImage, QObject *parent) :
    m_settings(settings),
    m_id(id),
    m_name(name),
    m_pathToImage(pathToImage),
    QObject(parent)
{
}

QImage UTEntity::getImage() const
{
    return QImage(m_pathToImage);
}

const UTEntity &UTEntity::operator =(const UTEntity &entity)
{
    m_settings = entity.settings();
    m_id = entity.id();
    m_name = entity.name();
    m_pathToImage = entity.pathToImage();
    setParent(entity.parent());

    return *this;
}
