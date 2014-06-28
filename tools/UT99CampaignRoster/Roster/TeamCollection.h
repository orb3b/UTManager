#ifndef TEAMCOLLECTION_H
#define TEAMCOLLECTION_H

#include "PawnGroup.h"

class TeamCollection : public PawnGroup
{
    Q_OBJECT
public:
    static const int MAX_GROUP_SIZE = 32;
public:
    TeamCollection(QObject *parent = 0);

    // Member managment functions
    bool addMember(const Pawn &member) OVERWRITE;

    // Export parameters
    QString exportPath() const;
    void setExportPath(const QString &path);

public slots:
    bool exportToIni();

private:    
    QString m_exportPath;

};

#endif // TEAMCOLLECTION_H
