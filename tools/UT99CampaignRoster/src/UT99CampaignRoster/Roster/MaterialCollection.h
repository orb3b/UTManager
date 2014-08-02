#ifndef MATERIALCOLLECTION_H
#define MATERIALCOLLECTION_H

#include "RosterObject.h"

class ClassCollection;

class MaterialCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit MaterialCollection(QObject *parent = 0);
    ~MaterialCollection();

    virtual bool isConsistent() const OVERWRITE;

    OWNED ClassCollection *classCollection();

signals:

public slots: 

private:
    QPointer<ClassCollection> m_classCollection;

};

#endif // MATERIALCOLLECTION_H
