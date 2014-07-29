#include "FaceCollection.h"

#include "PawnFace.h"

FaceCollection::FaceCollection(QObject *parent) :
    RosterObject(parent)
{
}

QList<PawnFace *> FaceCollection::allFaces() const
{
    clearError();

    QList<PawnFace *> result;

    foreach(RosterObject *obj, m_faces.data())
        result.append(qobject_cast<PawnFace *>(obj));

    return result;
}
