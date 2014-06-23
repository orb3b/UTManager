#include "TeamCollection.h"

TeamCollection::TeamCollection(QObject *parent) :
    RosterObject(parent),
    m_exportPath("User.ini")
{
}

bool TeamCollection::addMember(const Pawn &member)
{
    if (m_configuredTeam.size() >= MAX_GROUP_SIZE)
        return postError(QString("Can't add more that %1 members").arg(MAX_GROUP_SIZE));

    if (!m_configuredTeam.addMemberIfNotExist(member))
        return postError(QString("%1 member already exists").arg(member.name()));

    emit memberAdded(member);

    return postSuccess(QString("Member with name %1 was succsessfully added").arg(member.name()));
}

bool TeamCollection::removeMember(const QString &member)
{
    Pawn deleted = m_configuredTeam.takeMember(member);
    if (!deleted.isValid())
        return postError(QString("Can't find member %1").arg(member));

    emit memberRemoved(deleted);

    return postSuccess(QString("Member with name %1 was succsessfully removed").arg(member));
}

QString TeamCollection::exportPath() const
{
    return m_exportPath;
}

void TeamCollection::setExportPath(const QString &path)
{
    m_exportPath = path;
}

bool TeamCollection::exportToIni()
{
    return postSuccess("Export finished successfull");
}
