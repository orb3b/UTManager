#include "ClassCollection.h"

#include "PawnClass.h"

ClassCollection::ClassCollection(QObject *parent) :
    RosterObject(parent)
{
}

ClassCollection::~ClassCollection()
{

}

PawnClass *ClassCollection::getClass(const QString &name)
{
    clearError();

    foreach(RosterObject *obj, m_classes.data()) {
        PawnClass *pawnClass = qobject_cast<PawnClass *>(obj);
        if (pawnClass && pawnClass->name() == name)
            return pawnClass;
    }

    return nullptr;
}

QList<PawnClass *> ClassCollection::allClasses() const
{
    clearError();

    QList<PawnClass *> result;

    foreach(RosterObject *obj, m_classes.data())
        result.append(qobject_cast<PawnClass *>(obj));

    return result;
}

PawnClass *ClassCollection::first() const
{
    clearError();

    if (m_classes.data().isEmpty())
        return nullptr;

    return qobject_cast<PawnClass *>(m_classes.data().first());
}

