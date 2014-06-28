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
    if (member.isNull())
        return postError("Can't add member: member is null");

    int index = m_pawnList.indexOf(member);
    if (index < 0) {
        m_pawnList.append(member);

        emit memberAdded(member);

        return postSuccess(QString("Member %1 have been successfully added").arg(member.name()));
    }

    Pawn old = m_pawnList[index];
    m_pawnList[index] = member;

    emit memberChanged(old, member);

    return postSuccess(QString("Member %1 (new: %2) have been set successfully").arg(old.name(), member.name()));
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

    int index = m_pawnList.indexOf(member);
    if (index < 0)
        return postError(QString("Can't remove member %1: member didn't exist").arg(member.name()));

    emit memberRemoved(m_pawnList.takeAt(index));

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

bool PawnGroup::setMember(const QString &name, const Pawn &member)
{
    if (member.isNull())
        return postError("Can't set member: new member is null");

    int index = m_pawnList.indexOf(Pawn(name));
    if (index < 0)
        return postError(QString("Member with name %1 doesn't exists").arg(name));

    Pawn old = m_pawnList[index];
    m_pawnList[index] = member;

    emit memberChanged(old, member);

    return postSuccess(QString("Member %1 (new: %2) have been set successfully").arg(name, member.name()));
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
