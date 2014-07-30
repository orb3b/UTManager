#include "PawnClass.h"

#include "SkinCollection.h"

PawnClass::PawnClass(QObject *parent) :
    Material(parent),
    m_skinCollection(nullptr)
{
    createSkinCollection();
}

PawnClass::~PawnClass()
{
    deleteSkinCollection();
}

SkinCollection *PawnClass::skinCollection()
{
    return m_skinCollection;
}

void PawnClass::createSkinCollection()
{
    deleteSkinCollection();

    m_skinCollection = new SkinCollection();
    connect(m_skinCollection, SIGNAL(destroyed(QObject*)), SLOT(onMemberDestroyed(QObject*)));
}

void PawnClass::deleteSkinCollection()
{
    if (!m_skinCollection)
        return;

    disconnect(m_skinCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));

    delete m_skinCollection;
    m_skinCollection = nullptr;
}

void PawnClass::onMemberDestroyed(QObject *obj)
{
    if (obj == m_skinCollection) {
        m_skinCollection = nullptr;
        postError("Skin collection have been destroyed externally, going to recreate it");
        createSkinCollection();
        return;
    }
}
