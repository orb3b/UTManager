#ifndef CLASSCOLLECTION_H
#define CLASSCOLLECTION_H

#include "RosterObject.h"

#include "RosterContainer.h"

class PawnClass;

class ROSTER_EXPORT ClassCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit ClassCollection(QObject *parent = 0);
    ~ClassCollection();

    PawnClass *getClass(const QString &name);

    QList<PawnClass *> allClasses() const;

    PawnClass *first() const;

signals:

public slots:

private:
    RosterContainer m_classes;

};

#endif // CLASSCOLLECTION_H
