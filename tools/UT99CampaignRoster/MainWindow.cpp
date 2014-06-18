#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

#include "Logs.h"
#include "Roster/Roster.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui
    // ui - List's combo boxes
    connect(ui->cbPawnGroups, SIGNAL(currentIndexChanged(QString)), SLOT(uiLoadGroupMembers()));

    // ui - Buttons
    connect(ui->btnAddPawnToTeam, SIGNAL(clicked()), SLOT(onMovePawnToTeamClicked()));
    connect(ui->btnRemovePawnFromTeam, SIGNAL(clicked()), SLOT(onDeletePawnToTeamClicked()));
    ui->btnGenerate->addAction(ui->actionGenerate_Unreal_ini);

    // ui - Lists

    // ui - Group editor
    //connect(ui->actionPawn_groups_editor, )

    // configure roster
    m_roster = new Roster();

    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(uiOpenPawnCollection()));
    connect(ui->actionGenerate_Unreal_ini, SIGNAL(triggered()), m_roster->teamCollection(), SLOT(exportToIni()));

    connect(m_roster->pawnCollection(), SIGNAL(groupAdded(QString)), SLOT(onGroupAdded(QString)), Qt::QueuedConnection);
    connect(m_roster->pawnCollection(), SIGNAL(groupRemoved(QString)), SLOT(onGroupRemoved(QString)), Qt::QueuedConnection);
    connect(m_roster->pawnCollection(), SIGNAL(groupChanged(QString)), SLOT(onGroupChanged(QString)), Qt::QueuedConnection);

    connect(m_roster->teamCollection(), SIGNAL(memberAdded(Pawn)), SLOT(onTeamMemberAdded(Pawn)), Qt::QueuedConnection);
    connect(m_roster->teamCollection(), SIGNAL(memberRemoved(Pawn)), SLOT(onTeamMemberRemoved(Pawn)), Qt::QueuedConnection);

    connect(ui->actionQuit, SIGNAL(triggered()), SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_roster;
}

bool MainWindow::postError(const QString &text)
{
    sLogErr << text;

    QMessageBox::warning(this,
                         tr("Error"),
                         text
                         );

    return false;
}

QString MainWindow::nameFromShortDescription(const QString &description)
{
    QString result = description;
    if (result.endsWith("*"))
        result = result.left(result.size() - 1);

    int pos = result.indexOf("_");
    if (pos < 0)
        return result;

    return result.right(result.size() - pos - 1);
}

QString MainWindow::toShortDescription(const Pawn &member)
{
    return QString("%1_%2%3")
            .arg(member.lives())
            .arg(member.name())
            .arg(member.changed() ? "*" : "");
}

QColor MainWindow::teamColor(const Pawn &member)
{
    switch(member.team()){
    case Pawn::RedTeam:
        return QColor(Qt::red);
    case Pawn::BlueTeam:
        return QColor(Qt::blue);
    case Pawn::GreenTeam:
        return QColor(Qt::green);
    case Pawn::GoldTeam:
        return QColor(Qt::darkYellow);
    }

    return QColor(Qt::black);
}

void MainWindow::uiOpenPawnCollection()
{
    if (!m_roster->pawnCollection()->open("PawnCollection.ini"))
        postError(QString("Can't open pawn collection: %1").arg(m_roster->pawnCollection()->lastError()));
}

void MainWindow::onGroupAdded(QString groupName)
{
    ui->cbPawnGroups->addItem(groupName);
}

void MainWindow::onGroupRemoved(QString groupName)
{
    ui->cbPawnGroups->removeItem(ui->cbPawnGroups->findText(groupName));
}

void MainWindow::onGroupChanged(QString groupName)
{
    if (ui->cbPawnGroups->currentText() == groupName)
        uiLoadGroupMembers();
}

void MainWindow::uiLoadGroupMembers()
{
    PawnGroup *group = m_roster->pawnCollection()->getGroup(ui->cbPawnGroups->currentText());
    if (!group) {
        postError("Invalid group selected!");
        return;
    }

    ui->lwPawnGroupMembers->clear();

    foreach(QString memberName, group->getMemberNames())
        ui->lwPawnGroupMembers->addItem(memberName);
}

void MainWindow::onTeamMemberAdded(Pawn member)
{
    QListWidgetItem *item = new QListWidgetItem();

    item->setText(toShortDescription(member));
    item->setForeground(QBrush(teamColor(member)));

    ui->lwTeamMembers->addItem(item);
}

void MainWindow::onTeamMemberRemoved(Pawn member)
{
    foreach(QListWidgetItem *item, ui->lwTeamMembers->findItems(member.name()))
        delete item;
}

void MainWindow::onMovePawnToTeamClicked()
{
    QList<QListWidgetItem *> selected = ui->lwPawnGroupMembers->selectedItems();
    if (selected.isEmpty()) {
        postError("MainWindow::onMovePawnToTeamClicked member wasn't selected!");
        return;
    }

    PawnGroup *group = m_roster->pawnCollection()->getGroup(ui->cbPawnGroups->currentText());
    if (!group) {
        postError("MainWindow::onMovePawnToTeamClicked invalid group selected!");
        return;
    }

    foreach(QListWidgetItem *item, selected) {
        Pawn newMember = group->getMember(nameFromShortDescription(item->text()));
        if (!newMember.isValid()) {
            postError("MainWindow::onMovePawnToTeamClicked invalid member selected!");
            continue;
        }

        if (!m_roster->teamCollection()->addMember(newMember)) {
            postError(QString("Can't add member to team: %1").arg(m_roster->teamCollection()->lastError()));
            continue;
        }
    }

    // list will be updated when signal memberAdded will come from teamCollection
}

void MainWindow::onDeletePawnToTeamClicked()
{
    QList<QListWidgetItem *> selected = ui->lwTeamMembers->selectedItems();
    foreach(QListWidgetItem *item, selected) {
        if (!m_roster->teamCollection()->removeMember(nameFromShortDescription(item->text()))) {
            postError(QString("Can't remove member from team: %1").arg(m_roster->teamCollection()->lastError()));
            continue;
        }
    }

    // list will be updated when signal memberRemoved will come from teamCollection
}

void MainWindow::onRosterError(const QString &text)
{

}
