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

    ClassCollection *classCollection();

signals:

public slots:

private slots:
    void onMemberDestroyed(QObject *obj);

private:
    ClassCollection *m_classCollection;

};

#endif // MATERIALCOLLECTION_H
