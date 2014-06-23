#ifndef TEAMCOLLECTION_H
#define TEAMCOLLECTION_H

#include "RosterObject.h"

#include "PawnGroup.h"

class TeamCollection : public RosterObject
{
    Q_OBJECT
public:
    static const int MAX_GROUP_SIZE = 32;
public:
    TeamCollection(QObject *parent = 0);

    // Member managment functions
    bool addMember(const Pawn &member);
    bool removeMember(const QString &member);

    // Export parameters
    QString exportPath() const;
    void setExportPath(const QString &path);

public slots:
    bool exportToIni();

signals:
    void memberAdded(Pawn member);
    void memberRemoved(Pawn member);

private:
    PawnGroup m_configuredTeam;
    QString m_exportPath;

};

#endif // TEAMCOLLECTION_H
