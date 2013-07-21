#include "UTDataProvider.h"
#include "Model/UTPlayerModel.h"

UTDataProvider::UTDataProvider(QObject *parent) :
    QObject(parent)
{
    //moveToThread
    m_playerModel = new UTPlayerModel(this);
}

UTDataProvider::~UTDataProvider()
{
    delete m_playerModel;
}

int UTDataProvider::openProject(const QString &path)
{
    m_playerModel->loadEntities();

    return ErrorCode::OK;
}
