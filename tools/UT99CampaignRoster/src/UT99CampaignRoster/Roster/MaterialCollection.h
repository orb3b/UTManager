#ifndef MATERIALCOLLECTION_H
#define MATERIALCOLLECTION_H

#include "RosterObject.h"

class ClassCollection;
class WeaponCollection;

class ROSTER_EXPORT MaterialCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit MaterialCollection(QObject *parent = 0);
    ~MaterialCollection();

    virtual bool isConsistent() const OVERWRITE;

    OWNED ClassCollection *classCollection();
    OWNED WeaponCollection *weaponCollection();

signals:

public slots: 

private:
    QPointer<ClassCollection> m_classCollection;
    QPointer<WeaponCollection> m_weaponCollection;

};

#endif // MATERIALCOLLECTION_H
