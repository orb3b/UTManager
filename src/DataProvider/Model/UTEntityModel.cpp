#include "UTEntityModel.h"

UTEntityModel::UTEntityModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

UTEntityModel::~UTEntityModel()
{
    clearEntityList();
}

Qt::ItemFlags UTEntityModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

UTEntity *UTEntityModel::getEntityById(EntityID id)
{
    if (m_entityMap.contains(id))
        return m_entityMap.value(id);

    return NULL;
}

int UTEntityModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return m_entityMap.size();
}

QVariant UTEntityModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_entityMap.size())
        return QVariant();

    QHash<EntityID, UTEntity *>::const_iterator i = m_entityMap.constBegin();
    i += index.row();

    return QVariant::fromValue(*(i.value()));
}

bool UTEntityModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    emit dataChanged(index, index);
    return true;
}


void UTEntityModel::clearEntityList()
{
    foreach (EntityID id, m_entityMap.keys()) {
        delete m_entityMap.value(id);
    }
    m_entityMap.clear();
}
