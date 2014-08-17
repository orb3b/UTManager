#ifndef FACECOLLECTION_H
#define FACECOLLECTION_H

#include "RosterObject.h"

#include "RosterContainer.h"

class PawnFace;

class ROSTER_EXPORT FaceCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit FaceCollection(QObject *parent = 0);

    QList<PawnFace *> allFaces() const;

signals:

public slots:

private:
    RosterContainer m_faces;

};

#endif // FACECOLLECTION_H
