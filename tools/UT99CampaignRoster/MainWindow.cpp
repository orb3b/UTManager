#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

#include "Logs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui
    // ui - List's combo boxes
    connect(ui->cbPawnGroups, SIGNAL(currentIndexChanged(QString)), SLOT(uiLoadGroupMembers()));

    // ui - Buttons
    connect(ui->btnAddPawnToTeam, SIGNAL(clicked()), SLOT(uiOnMovePawnToTeamClicked()));
    connect(ui->btnRemovePawnFromTeam, SIGNAL(clicked()), SLOT(uiOnDeletePawnToTeamClicked()));
    ui->btnGenerate->addAction(ui->actionGenerate_Unreal_ini);

    // ui - Lists
    connect(ui->lwPawnGroupMembers, SIGNAL(itemDoubleClicked(QListWidgetItem *)), SLOT(uiOnPawnGroupMemberDoubleClicked(QListWidgetItem *)));

    connect(ui->lwTeamMembers, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(uiOnTeamMemberDoubleClicked(QListWidgetItem*)));

    // ui - Group editor
    //connect(ui->actionPawn_groups_editor, )

    // ui -> Actions
    ui->actionOpen->setShortcut(QKeySequence(tr("Ctrl+O")));

    // ui - Editors
    m_pawnEditor = new PawnEditor(this);

    // configure roster
    m_roster = new Roster();

    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(uiOpenProject()));
    connect(ui->actionGenerate_Unreal_ini, SIGNAL(triggered()), m_roster->teamCollection(), SLOT(exportToIni()));

    connect(m_roster->pawnCollection(), SIGNAL(groupAdded(QString)), SLOT(onGroupAdded(QString)), Qt::QueuedConnection);
    connect(m_roster->pawnCollection(), SIGNAL(groupRemoved(QString)), SLOT(onGroupRemoved(QString)), Qt::QueuedConnection);
    connect(m_roster->pawnCollection(), SIGNAL(groupChanged(QString)), SLOT(onGroupChanged(QString)), Qt::QueuedConnection);

    connect(m_roster->teamCollection(), SIGNAL(memberAdded(Pawn)), SLOT(onTeamMemberAdded(Pawn)), Qt::QueuedConnection);
    connect(m_roster->teamCollection(), SIGNAL(memberRemoved(Pawn)), SLOT(onTeamMemberRemoved(Pawn)), Qt::QueuedConnection);
    connect(m_roster->teamCollection(), SIGNAL(memberChanged(Pawn,Pawn)), SLOT(onTeamMemberChanged(Pawn, Pawn)), Qt::QueuedConnection);

    connect(ui->actionQuit, SIGNAL(triggered()), SLOT(close()));

    uiOpenProject();
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

QString MainWindow::nameFromShortDescription(const QString &description) const
{
    QString result = description;
    if (result.endsWith("*"))
        result = result.left(result.size() - 1);

    int pos = result.indexOf("_");
    if (pos < 0)
        return result;

    return result.right(result.size() - pos - 1);
}

QString MainWindow::toShortDescription(const Pawn &member) const
{
    return QString("%1_%2%3")
            .arg(member.lives())
            .arg(member.name())
            .arg(member.changed() ? "*" : "");
}

QColor MainWindow::teamColor(const Pawn &member) const
{
    switch(member.team()){
    case Pawn::Red:
        return QColor(Qt::red);
    case Pawn::Blue:
        return QColor(Qt::blue);
    case Pawn::Green:
        return QColor(Qt::green);
    case Pawn::Gold:
        return QColor(Qt::darkYellow);
    default:
        return QColor(Qt::black);
    }

    return QColor(Qt::black);
}

QListWidgetItem *MainWindow::itemFromPawn(const Pawn &pawn)
{
    if (pawn.isNull())
        return nullptr;

    QListWidgetItem *item = new QListWidgetItem();

    updateItem(item, pawn);

    return item;
}

void MainWindow::updateItem(QListWidgetItem *item, const Pawn &pawn)
{
    if (!item)
        return;

    if (pawn.isNull())
        return;

    item->setText(toShortDescription(pawn));
    item->setForeground(QBrush(teamColor(pawn)));
}

PawnGroup *MainWindow::uiGetCurrentGroup()
{
    PawnGroup *group = m_roster->pawnCollection()->getGroup(ui->cbPawnGroups->currentText());
    if (!group) {
        postError("Invalid group selected!");
        return nullptr;
    }

    return group;
}

Pawn MainWindow::uiGetMemberFromItem(const PawnGroup *group, const QListWidgetItem *item)
{
    if (!group) {
        postError("Invalid group selected!");
        return Pawn::Null();;
    }

    if (!item) {
        postError("Invalid item selected");
        return Pawn::Null();
    }

    Pawn member = group->getMember(nameFromShortDescription(item->text()));
    if (member.isNull())
        postError("Invalid member selected");

    return member;
}

void MainWindow::uiEditItem(QListWidgetItem *item, PawnEditor::EditorMode mode)
{
    if (!item)
        return;

    PawnGroup *currentGroup = mode == PawnEditor::EditGroupMember ? uiGetCurrentGroup() : m_roster->teamCollection();
    if (!currentGroup)
        return;

    Pawn oldMember = uiGetMemberFromItem(currentGroup, item);
    if (oldMember.isNull())
        return;

    m_pawnEditor->setMode(mode);
    if (m_pawnEditor->execEditor(oldMember) == QDialog::Rejected)
        return;

    // Accepted
    if (!currentGroup->setMember(oldMember.name(), m_pawnEditor->getMember())){
        postError(QString("Can't save group %1 member: %2").arg(currentGroup->name(), currentGroup->lastError()));
        return;
    }

    if (mode == PawnEditor::EditGroupMember)
        uiLoadGroupMembers();

    // team list will be updated by signals
}

void MainWindow::uiOpenProject()
{
    if (!m_roster->openProject("Project.ini"))
        postError(QString("Can't open project: %1").arg(m_roster->pawnCollection()->lastError()));
}

void MainWindow::uiLoadGroupMembers()
{
    PawnGroup *group = m_roster->pawnCollection()->getGroup(ui->cbPawnGroups->currentText());
    if (!group) {
        postError("Invalid group selected!");
        return;
    }

    ui->lwPawnGroupMembers->clear();

    foreach(const Pawn &member, group->allMembers())
        ui->lwPawnGroupMembers->addItem(itemFromPawn(member));
}

void MainWindow::uiOnPawnGroupMemberDoubleClicked(QListWidgetItem *item)
{
    uiEditItem(item, PawnEditor::EditGroupMember);
}

void MainWindow::uiOnTeamMemberDoubleClicked(QListWidgetItem *item)
{
    uiEditItem(item, PawnEditor::EditTeamMember);
}

void MainWindow::uiOnMovePawnToTeamClicked()
{
    QList<QListWidgetItem *> selected = ui->lwPawnGroupMembers->selectedItems();
    if (selected.isEmpty()) {
        postError("MainWindow::onMovePawnToTeamClicked member wasn't selected!");
        return;
    }

    PawnGroup *group = uiGetCurrentGroup();
    if (!group)
        return;

    foreach(QListWidgetItem *item, selected) {
        Pawn newMember = uiGetMemberFromItem(group, item);
        if (newMember.isNull())
            continue;        

        if (!m_roster->teamCollection()->addMember(newMember)) {
            postError(QString("Can't add member to team: %1").arg(m_roster->teamCollection()->lastError()));
            continue;
        }
    }

    // list will be updated when signal memberAdded will come from teamCollection
}

void MainWindow::uiOnDeletePawnToTeamClicked()
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

void MainWindow::onTeamMemberAdded(Pawn member)
{
    ui->lwTeamMembers->addItem(itemFromPawn(member));
}

void MainWindow::onTeamMemberRemoved(Pawn member)
{
    foreach(QListWidgetItem *item, ui->lwTeamMembers->findItems(toShortDescription(member), Qt::MatchExactly))
        delete item;
}

void MainWindow::onTeamMemberChanged(Pawn oldMember, Pawn newMember)
{
    foreach(QListWidgetItem *item, ui->lwTeamMembers->findItems(toShortDescription(oldMember), Qt::MatchExactly))
        updateItem(item, newMember);
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

void MainWindow::onRosterError(const QString &text)
{

}
