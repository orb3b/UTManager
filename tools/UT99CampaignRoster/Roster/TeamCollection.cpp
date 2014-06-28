#include "TeamCollection.h"

TeamCollection::TeamCollection(QObject *parent) :
    PawnGroup("TeamCollection", Pawn::None, parent),
    m_exportPath("User.ini")
{
}

bool TeamCollection::addMember(const Pawn &member)
{
    if (size() >= MAX_GROUP_SIZE)
        return postError(QString("Can't add more that %1 members").arg(MAX_GROUP_SIZE));

    return PawnGroup::addMember(member);
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
