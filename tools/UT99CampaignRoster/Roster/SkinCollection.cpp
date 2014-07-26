#include "SkinCollection.h"

#include "PawnSkin.h"

SkinCollection::SkinCollection(QObject *parent) :
    RosterObject(parent)
{
}

PawnSkin *SkinCollection::getSkin(const QString &name)
{
    clearError();

    foreach(RosterObject *obj, m_skins.data()) {
        PawnSkin *pawnSkin = qobject_cast<PawnSkin *>(obj);
        if (pawnSkin && pawnSkin->name() == name)
            return pawnSkin;
    }

    return nullptr;
}

QList<PawnSkin *> SkinCollection::allSkins() const
{
    clearError();

    QList<PawnSkin *> result;

    foreach(RosterObject *obj, m_skins.data())
        result.append(qobject_cast<PawnSkin *>(obj));

    return result;
}
