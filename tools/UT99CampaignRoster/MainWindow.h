#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "Roster/Roster.h"

class QAction;
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual bool postError(const QString &text);

private:
    QString nameFromShortDescription(const QString &description) const;
    QString toShortDescription(const Pawn &member) const;
    QColor teamColor(const Pawn &member) const;

    // Ui - private
    PawnGroup *uiGetCurrentGroup();
    Pawn uiGetMemberFromItem(const PawnGroup *group, const QListWidgetItem *item);
    QListWidgetItem *itemFromPawn(const Pawn &pawn);

private slots:
    // Commands from ui
    void uiOpenProject();

    void uiLoadGroupMembers();

    void uiOnPawnGroupMemberDoubleClicked(QListWidgetItem *item);

    void uiOnMovePawnToTeamClicked();
    void uiOnDeletePawnToTeamClicked();

    // Events from roster
    void onGroupAdded(QString groupName);
    void onGroupRemoved(QString groupName);
    void onGroupChanged(QString groupName);

    void onTeamMemberAdded(Pawn member);
    void onTeamMemberRemoved(Pawn member);

    void onRosterError(const QString &text);

private:
    Ui::MainWindow *ui;

    Roster *m_roster;
};

#endif // MAINWINDOW_H
