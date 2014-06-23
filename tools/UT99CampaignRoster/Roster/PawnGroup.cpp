#include "PawnGroup.h"

PawnGroup::PawnGroup(const QString &name, Pawn::Team defaultTeam, QObject *parent) :
    QObject(parent)
{
    setName(name);
    setDefaultTeam(defaultTeam);
}

PawnGroup::~PawnGroup()
{
    m_pawnList.clear();
}

QString PawnGroup::name() const
{
    return m_name;
}

void PawnGroup::setName(const QString &name)
{
    m_name = name;
}

Pawn::Team PawnGroup::defaultTeam() const
{
    return m_defaultTeam;
}

void PawnGroup::setDefaultTeam(Pawn::Team team)
{
    m_defaultTeam = team;

    if (m_defaultTeam != Pawn::None)
        for(int i = 0; i< m_pawnList.size(); i++)
            m_pawnList[i].setTeam(m_defaultTeam);
}

void PawnGroup::addMember(const Pawn &member)
{
    setMember(member);
}

bool PawnGroup::addMemberIfNotExist(const Pawn &member)
{
    if (contains(member))
        return false;

    addMember(member);

    return true;
}

void PawnGroup::removeMember(const Pawn &member)
{
    m_pawnList.removeAll(member);
}

Pawn PawnGroup::takeMember(const QString &memberName)
{
    for(int i = 0; i < m_pawnList.size(); i++)
        if (m_pawnList[i].name() == memberName)
            return m_pawnList.takeAt(i);

    return Pawn::Invalid();
}

bool PawnGroup::contains(const Pawn &member)
{
    return m_pawnList.contains(member);
}

Pawn PawnGroup::getMember(const QString &name) const
{
    foreach(Pawn p, m_pawnList)
        if (p.name() == name)
            return p;

    return Pawn::Invalid();
}

void PawnGroup::setMember(const Pawn &member)
{
    int index = m_pawnList.indexOf(member);
    if (index < 0) {
        m_pawnList.append(member);
        if (m_defaultTeam != Pawn::None)
            m_pawnList.last().setTeam(m_defaultTeam);
        return;
    }

    m_pawnList[index] = member;
    if (m_defaultTeam != Pawn::None)
        m_pawnList[index].setTeam(m_defaultTeam);
}

QStringList PawnGroup::getMemberNames() const
{
    QStringList result;
    foreach(const Pawn &p, m_pawnList)
        result << p.name();

    return result;
}

int PawnGroup::size() const
{
    return m_pawnList.size();
}
