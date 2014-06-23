#include "PawnCollection.h"

#include "PawnGroup.h"

PawnCollection::PawnCollection(QObject *parent) :
    RosterObject(parent)
{
}

PawnCollection::~PawnCollection()
{
    foreach(PawnGroup *group, m_groupList) {
        disconnect(group, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberGroupDestroyed(QObject*)));
        delete group;
    }

    m_groupList.clear();
}

bool PawnCollection::open(const QString &path)
{
    PawnGroup *testGroup[2];

    testGroup[0] = new PawnGroup("Angels", Pawn::Blue);
    testGroup[0]->addMember(Pawn("Ivana", Pawn::Blue));
    testGroup[0]->addMember(Pawn("Alena", Pawn::Blue));
    testGroup[0]->addMember(Pawn("Freylis", Pawn::Blue));

    testGroup[1] = new PawnGroup("Legion", Pawn::Red);
    testGroup[1]->addMember(Pawn("Berserker"));
    testGroup[1]->addMember(Pawn("Devastator"));
    testGroup[1]->addMember(Pawn("WarCow"));
    testGroup[1]->addMember(Pawn("Proj.Zero"));
    testGroup[1]->addMember(Pawn("Plasma"));
    testGroup[1]->addMember(Pawn("Karlson"));
    testGroup[1]->addMember(Pawn("Fury"));

    return addGroup(testGroup[0]) && addGroup(testGroup[1]);
}

PawnGroup *PawnCollection::getGroup(const QString &groupName)
{
    foreach (PawnGroup *group, m_groupList) {
        if (group->name() == groupName)
            return group;
    }

    return nullptr;
}

bool PawnCollection::addGroup(PawnGroup *group)
{
    if (!addGroup_P(group))
        return false;

    emit groupAdded(group->name());

    return postSuccess(QString("Group %1 was successfully added").arg(group->name()));
}

bool PawnCollection::addGroup_P(PawnGroup *group)
{
    if (!group)
        return postError("Can't add null pointer group");

    connect(group, SIGNAL(destroyed(QObject*)), SLOT(onMemberGroupDestroyed(QObject*)));

    m_groupList.append(group);

    return true;
}

bool PawnCollection::removeGroup_P(PawnGroup *group)
{
    if (!group)
        return postError("Can't remove null pointer group");

    disconnect(group, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberGroupDestroyed(QObject*)));

    delete group;

    m_groupList.removeAll(group);

    return true;
}

void PawnCollection::onMemberGroupDestroyed(QObject *obj)
{
    PawnGroup *deleted = qobject_cast<PawnGroup *>(obj);
    if (!deleted)
        return;

    m_groupList.removeAll(deleted);
}
