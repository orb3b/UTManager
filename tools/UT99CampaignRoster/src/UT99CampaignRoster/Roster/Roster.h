#ifndef ROSTER_H
#define ROSTER_H

#include "RosterObject.h"

#include "PawnCollection.h"
#include "TeamCollection.h"
#include "MaterialCollection.h"

class RosterDataProvider;

class ROSTER_EXPORT Roster : public RosterObject
{
    Q_OBJECT
public:
    Roster(QObject *parent = 0);
    ~Roster();

    virtual bool isConsistent() const OVERWRITE;

    bool openProject(const QString &path);    

    OWNED PawnCollection *pawnCollection() const;
    OWNED TeamCollection *teamCollection() const;
    OWNED MaterialCollection *materialCollection() const;

signals:

public slots:

private:
    void registerMetatypes();

private:
    QPointer<PawnCollection> m_pawnCollection;
    QPointer<TeamCollection> m_teamCollection;
    QPointer<MaterialCollection> m_materialCollection;

    QPointer<RosterDataProvider> m_provider;
};

#endif // ROSTER_H
