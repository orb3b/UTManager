#include "ClassCollection.h"

ClassCollection::ClassCollection(QObject *parent) :
    RosterCollection(parent)
{
}

ClassCollection::~ClassCollection()
{

}

QList<const PawnClass *> ClassCollection::allClasses() const
{
    clearError();

    QList<const PawnClass *> result;

    foreach (RosterObject *obj, m_objectList)
        result.append(qobject_cast<const PawnClass *>(obj));

    return result;
}

const PawnClass *ClassCollection::first() const
{
    if (size() < 1) {
        postError("Can't retrieve first member: collection is empty");
        return nullptr;
    }

    clearError();

    return qobject_cast<PawnClass *>(m_objectList.first());
}
