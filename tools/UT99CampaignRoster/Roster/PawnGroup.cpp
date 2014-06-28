#include "PawnGroup.h"

#include "Logs.h"

PawnGroup::PawnGroup(const QString &name, Pawn::Team defaultTeam, QObject *parent) :
    RosterObject(parent)
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

bool PawnGroup::setName(const QString &name)
{
    if (name.isEmpty())
        return postError("Can't set group name: name is empty");

    m_name = name;

    return postSuccess("Group name have been changed successfully");
}

Pawn::Team PawnGroup::defaultTeam() const
{
    return m_defaultTeam;
}

bool PawnGroup::setDefaultTeam(Pawn::Team team)
{
    m_defaultTeam = team;

    if (m_defaultTeam != Pawn::None)
        for(int i = 0; i< m_pawnList.size(); i++)
            m_pawnList[i].setTeam(m_defaultTeam);

    return postSuccess("Default team have been changed successfully");
}

bool PawnGroup::addMember(const Pawn &member)
{
    return setMember(member);
}

bool PawnGroup::addMemberIfNotExist(const Pawn &member)
{
    if (member.isNull())
        return postError("Can't add member: member is Null");

    if (contains(member))
        return postError(QString("Can't add member %1: member already exists").arg(member.name()));

    return addMember(member);
}

bool PawnGroup::removeMember(const Pawn &member)
{
    if (member.isNull())
        return postError("Can't remove member: member is Null");

    m_pawnList.removeAll(member);

    emit memberRemoved(member);

    return postSuccess(QString("Member %1 have been removed successfully").arg(member.name()));
}

Pawn PawnGroup::takeMember(const QString &memberName)
{
    clearError();

    for(int i = 0; i < m_pawnList.size(); i++)
        if (m_pawnList[i].name() == memberName) {

            emit memberRemoved(m_pawnList[i]);

            return m_pawnList.takeAt(i);
        }

    return Pawn::Null();
}

bool PawnGroup::contains(const Pawn &member) const
{
    clearError();

    if (member.isNull())
        return postError("Can't check existance of null member");

    return m_pawnList.contains(member);
}

Pawn PawnGroup::getMember(const QString &name) const
{
    clearError();

    foreach(Pawn p, m_pawnList)
        if (p.name() == name)
            return p;

    return Pawn::Null();
}

const QList<Pawn> &PawnGroup::allMembers() const
{
    clearError();
    return m_pawnList;
}

bool PawnGroup::setMember(const Pawn &member)
{
    if (member.isNull())
        return postError("Can't set null member");

    int index = m_pawnList.indexOf(member);
    // Adding member
    if (index < 0) {
        m_pawnList.append(member);
        if (m_defaultTeam != Pawn::None)
            m_pawnList.last().setTeam(m_defaultTeam);

        emit memberAdded(member);

        return postSuccess(QString("Member %1 have been added successfully").arg(member.name()));
    }

    m_pawnList[index] = member;
    if (m_defaultTeam != Pawn::None)
        m_pawnList[index].setTeam(m_defaultTeam);

    emit memberChanged(member);

    return postSuccess(QString("Member %1 have been set successfully").arg(member.name()));
}

QStringList PawnGroup::getMemberNames() const
{
    clearError();

    QStringList result;
    foreach(const Pawn &p, m_pawnList)
        result << p.name();

    return result;
}

int PawnGroup::size() const
{
    clearError();
    return m_pawnList.size();
}

void PawnGroup::logError(const QString &text) const
{
    sLogErr << QString("[%1](%2) %3").arg(_CLASS_NAME_, m_name, text);
}

void PawnGroup::logMessage(const QString &text) const
{
    sLogDbg << QString("[%1](%2) %3").arg(_CLASS_NAME_, m_name, text);
}

void PawnGroup::logSuccess(const QString &text) const
{
    sLogMsg << QString("[%1](%2) %3").arg(_CLASS_NAME_, m_name, text);
}
