#ifndef ROSTER_H
#define ROSTER_H

#include "RosterObject.h"

class PawnCollection;
class TeamCollection;

class Roster : public RosterObject
{
    Q_OBJECT
public:
    Roster(QObject *parent = 0);
    ~Roster();

    PawnCollection *pawnCollection();
    TeamCollection *teamCollection();

signals:

public slots:

private slots:
    void onMemberDestroyed(QObject *obj);

private:
    PawnCollection *m_pawnCollection;
    TeamCollection *m_teamCollection;
};

#endif // ROSTER_H
