#ifndef TEAMMEMBERSWIDGET_H
#define TEAMMEMBERSWIDGET_H

#include <QWidget>
#include "Roster/RosterComponent.h"

#include "Roster/Pawn.h"
#include "PawnConverter.h"

class PawnEditor;
class TeamCollection;
class PawnGroup;
class QListWidgetItem;

namespace Ui {
class TeamMembersWidget;
}

class TeamMembersWidget : public QWidget,
                          public RosterComponent
{
    Q_OBJECT

public:
    explicit TeamMembersWidget(QWidget *parent = 0);
    ~TeamMembersWidget();

    void setTeamCollection(TeamCollection *collection);
    void setPawnEditor(PawnEditor *editor);

    bool addMember(const Pawn &member);
    bool removeCurrentMember();

protected:
    virtual void notifyError(const QString &text) const OVERWRITE;
    virtual void notifyWarning(const QString &text) const OVERWRITE;

private:

private slots:
    void editItem(QListWidgetItem *item);

    // Events from roster
    void onTeamMemberAdded(Pawn member);
    void onTeamMemberRemoved(Pawn member);
    void onTeamMemberChanged(Pawn oldMember, Pawn newMember);

    // Handle deleting external components
    void onDestroyed(QObject *obj);

private:
    Ui::TeamMembersWidget *ui;

    TeamCollection *m_teamCollection;
    PawnEditor *m_pawnEditor;

    PawnConverter m_converter;
};

#endif // TEAMMEMBERSWIDGET_H
