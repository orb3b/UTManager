#ifndef PAWNGROUP_H
#define PAWNGROUP_H

#include <QObject>
#include <QList>
#include <QString>
#include <QStringList>

#include "Pawn.h"

class PawnGroup : public QObject
{    
    Q_OBJECT
public:
    PawnGroup(const QString &name = QString("PawnGroup"), Pawn::Team defaultTeam = Pawn::None, QObject *parent = 0);
    ~PawnGroup();

    // Group properties

    QString name() const;
    void setName(const QString &name);

    Pawn::Team defaultTeam() const;
    void setDefaultTeam(Pawn::Team team);

    // Member properties

    void addMember(const Pawn &member);
    bool addMemberIfNotExist(const Pawn &member);
    void removeMember(const Pawn &member);
    Pawn takeMember(const QString &memberName);

    bool contains(const Pawn &member);
    Pawn getMember(const QString &name) const;
    void setMember(const Pawn &member);

    QStringList getMemberNames() const;

    int size() const;

private:
    QString m_name;
    Pawn::Team m_defaultTeam;

    QList<Pawn> m_pawnList;

};

#endif // PAWNGROUP_H
