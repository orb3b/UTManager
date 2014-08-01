#ifndef ROSTER_H
#define ROSTER_H

#include "RosterObject.h"

#include "PawnCollection.h"
#include "TeamCollection.h"
#include "MaterialCollection.h"

class RosterDataProvider;

class Roster : public RosterObject
{
    Q_OBJECT
public:
    Roster(QObject *parent = 0);
    ~Roster();

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

    RosterDataProvider *m_provider;
};

#endif // ROSTER_H
