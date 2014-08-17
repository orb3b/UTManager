#ifndef PAWNGROUPSWIDGET_H
#define PAWNGROUPSWIDGET_H

#include <QWidget>
#include <RosterComponent.h>

#include <QList>
#include <Pawn.h>

#include "PawnConverter.h"

class PawnEditor;
class PawnCollection;
class PawnGroup;
class QListWidgetItem;

namespace Ui {
class PawnGroupsWidget;
}

class PawnGroupsWidget : public QWidget,
                         public RosterComponent
{
    Q_OBJECT

public:
    explicit PawnGroupsWidget(QWidget *parent = 0);
    ~PawnGroupsWidget();

    void setPawnCollection(PawnCollection *collection);
    void setPawnEditor(PawnEditor *editor);

    QList<Pawn> getSelectedPawns();
    PawnGroup *getCurrentGroup();

protected:
    virtual void notifyError(const QString &text) const OVERWRITE;
    virtual void notifyWarning(const QString &text) const OVERWRITE;

private:

private slots:
    void loadCurrentGroupMembers();
    void editItem(QListWidgetItem *item);

    // Events from roster
    void onGroupAdded(QString groupName);
    void onGroupRemoved(QString groupName);
    void onGroupChanged(QString groupName);

    // Handle deleting external components
    void onDestroyed(QObject *obj);

private:
    Ui::PawnGroupsWidget *ui;

    PawnCollection *m_pawnCollection;
    PawnEditor *m_pawnEditor;

    PawnConverter m_converter;
};

#endif // PAWNGROUPSWIDGET_H
