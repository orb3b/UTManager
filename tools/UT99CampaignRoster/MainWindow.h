#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "Roster/Roster.h"

class QAction;

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
    QString nameFromShortDescription(const QString &description);
    QString toShortDescription(const Pawn &member);
    QColor teamColor(const Pawn &member);

private slots:
    void uiOpenPawnCollection();

    void onGroupAdded(QString groupName);
    void onGroupRemoved(QString groupName);
    void onGroupChanged(QString groupName);

    void uiLoadGroupMembers();

    void onTeamMemberAdded(Pawn member);
    void onTeamMemberRemoved(Pawn member);

    void onMovePawnToTeamClicked();
    void onDeletePawnToTeamClicked();

    void onRosterError(const QString &text);

private:
    Ui::MainWindow *ui;

    Roster *m_roster;
};

#endif // MAINWINDOW_H
