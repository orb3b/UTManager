#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include <Roster.h>

#include "PawnEditor.h"

class QAction;
class QListWidgetItem;
class PawnGroupsWidget;
class TeamMembersWidget;
class InteractionWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,
                   public RosterComponent
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void notifyError(const QString &text) const OVERWRITE;
    virtual void notifyWarning(const QString &text) const OVERWRITE;

private:      

private slots:
    // Commands from ui
    void openProject();

    void addPawnToTeam();
    void removePawnFromTeam();

private:
    Ui::MainWindow *ui;

    // Child widgets
    PawnEditor *m_pawnEditor;
    PawnGroupsWidget *m_pawnGroupsWidget;
    TeamMembersWidget *m_teamMembersWidget;
    InteractionWidget *m_interactionWidget;

    Roster *m_roster;
};

#endif // MAINWINDOW_H
