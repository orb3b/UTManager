#include "UTPlayerModel.h"

UTPlayerModel::UTPlayerModel(QObject *parent) :
    UTEntityModel(parent)
{
}

UTPlayerModel::~UTPlayerModel()
{
}

int UTPlayerModel::loadEntities()
{
    sLogMsg << "UTPlayerModel::loadEntities";

    m_entityMap.insert(1, new UTEntity(NULL, 1, "Skylla"));
    m_entityMap.insert(2, new UTEntity(NULL, 2, "Elly"));
    m_entityMap.insert(3, new UTEntity(NULL, 3, "Jakob"));

    return ErrorCode::OK;
}

int UTPlayerModel::saveEntities()
{
    return ErrorCode::OK;
}
