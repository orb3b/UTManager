#ifndef CLASSCOLLECTION_H
#define CLASSCOLLECTION_H

#include "RosterCollection.h"

class PawnClass;

class ClassCollection : public RosterCollection
{
    Q_OBJECT
public:
    explicit ClassCollection(QObject *parent = 0);
    ~ClassCollection();

    QList<const PawnClass *> allClasses() const;

    const PawnClass *first() const;

signals:

public slots:

};

#endif // CLASSCOLLECTION_H
