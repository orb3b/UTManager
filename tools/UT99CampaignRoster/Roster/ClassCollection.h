#ifndef CLASSCOLLECTION_H
#define CLASSCOLLECTION_H

#include "RosterCollection.h"
#include <QObject>

class PawnClass;

class ClassCollection : public RosterCollection<PawnClass>
{
    Q_OBJECT
public:
    explicit ClassCollection(QObject *parent = 0);
    ~ClassCollection();

signals:

public slots:

};

#endif // CLASSCOLLECTION_H
