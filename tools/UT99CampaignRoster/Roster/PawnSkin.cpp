#include "PawnSkin.h"

#include "FaceCollection.h"

PawnSkin::PawnSkin(QObject *parent) :
    Material(parent)
{
    createFaceCollection();
}

PawnSkin::~PawnSkin()
{
    deleteFaceCollection();
}

FaceCollection *PawnSkin::faceCollection()
{
    return m_faceCollection;
}

void PawnSkin::createFaceCollection()
{
    deleteFaceCollection();

    m_faceCollection = new FaceCollection();
    connect(m_faceCollection, SIGNAL(destroyed(QObject*)), SLOT(onMemberDestroyed(QObject*)));
}

void PawnSkin::deleteFaceCollection()
{
    if (!m_faceCollection)
        return;

    disconnect(m_faceCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));

    delete m_faceCollection;
    m_faceCollection = nullptr;
}

void PawnSkin::onMemberDestroyed(QObject *obj)
{
    if (obj == m_faceCollection) {
        m_faceCollection = nullptr;
        postError("Face collection have been destroyed externally, going to recreate it");
        createFaceCollection();
        return;
    }
}
