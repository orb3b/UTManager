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
    return ErrorCode::OK;
}

int UTPlayerModel::saveEntities()
{
    return ErrorCode::OK;
}
