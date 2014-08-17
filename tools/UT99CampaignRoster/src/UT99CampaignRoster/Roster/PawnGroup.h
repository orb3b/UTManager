#ifndef PAWNGROUP_H
#define PAWNGROUP_H

/*
 * Container for pawns
 * NOTE: It check that pawns passed to it aren't Null, i. e. pawn.isNull() should return false
 *
*/

#include "RosterObject.h"

#include <QList>
#include <QString>
#include <QStringList>

#include "Pawn.h"

class ROSTER_EXPORT PawnGroup : public RosterObject
{    
    Q_OBJECT
public:
    PawnGroup(const QString &name = QString("PawnGroup"), Pawn::Team defaultTeam = Pawn::None, QObject *parent = 0);
    ~PawnGroup();

    // Group properties

    // Group's name
    QString name() const;
    bool setName(const QString &name);

    // Group's default team
    // If defaultTeam != None all pawns in group will belong to defaultTeam
    // Changing team for group causes changing team for all pawns in it
    Pawn::Team defaultTeam() const;
    bool setDefaultTeam(Pawn::Team team);

    // Member properties
    // Member passed will be checked for Null property

    virtual bool addMember(const Pawn &member);
    bool addMemberIfNotExist(const Pawn &member);
    bool removeMember(const Pawn &member);
    Pawn takeMember(const QString &memberName);    

    bool contains(const Pawn &member) const;
    Pawn getMember(const QString &name) const;
    const QList<Pawn> &allMembers() const;
    bool setMember(const QString &name, const Pawn &member);

    QStringList getMemberNames() const;

    int size() const;

signals:
    void memberAdded(Pawn member);
    void memberRemoved(Pawn member);
    void memberChanged(Pawn oldPawn, Pawn newPawn);

protected:
    virtual void logError(const QString &text) const OVERWRITE;
    virtual void logWarning(const QString &text) const OVERWRITE;
    virtual void logMessage(const QString &text) const OVERWRITE;
    virtual void logSuccess(const QString &text) const OVERWRITE;

private:
    QString m_name;
    Pawn::Team m_defaultTeam;

    QList<Pawn> m_pawnList;

};

#endif // PAWNGROUP_H
