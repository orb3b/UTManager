#include "TeamMembersWidget.h"
#include "ui_TeamMembersWidget.h"

#include <QMessageBox>

#include <TeamCollection.h>

#include "PawnEditor.h"

TeamMembersWidget::TeamMembersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamMembersWidget),
    m_teamCollection(nullptr),
    m_pawnEditor(nullptr)
{
    ui->setupUi(this);

    // Ui - lists
    connect(ui->lwTeamMembers, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(editItem(QListWidgetItem*)));
}

TeamMembersWidget::~TeamMembersWidget()
{
    delete ui;
}

void TeamMembersWidget::setTeamCollection(TeamCollection *collection)
{
    if (m_teamCollection) {
        disconnect(m_teamCollection, SIGNAL(memberAdded(Pawn)), this, SLOT(onTeamMemberAdded(Pawn)));
        disconnect(m_teamCollection, SIGNAL(memberRemoved(Pawn)), this, SLOT(onTeamMemberRemoved(Pawn)));
        disconnect(m_teamCollection, SIGNAL(memberChanged(Pawn,Pawn)), this, SLOT(onTeamMemberChanged(Pawn,Pawn)));

        disconnect(m_teamCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    }

    m_teamCollection = collection;

    connect(m_teamCollection, SIGNAL(memberAdded(Pawn)), SLOT(onTeamMemberAdded(Pawn)));
    connect(m_teamCollection, SIGNAL(memberRemoved(Pawn)), SLOT(onTeamMemberRemoved(Pawn)));
    connect(m_teamCollection, SIGNAL(memberChanged(Pawn,Pawn)), SLOT(onTeamMemberChanged(Pawn,Pawn)));

    connect(m_teamCollection, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)));
}

void TeamMembersWidget::setPawnEditor(PawnEditor *editor)
{
    if (m_pawnEditor) {
        disconnect(m_pawnEditor, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    }

    m_pawnEditor = editor;

    connect(m_pawnEditor, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)));
}

bool TeamMembersWidget::addMember(const Pawn &member)
{
    if (!m_teamCollection)
        return postError("Can't add member to team: team collection is null");

    if (!m_teamCollection->addMemberIfNotExist(member))
        return postError(QString("Can't add member to team: %1").arg(m_teamCollection->lastError()));

    return true;
}

bool TeamMembersWidget::removeCurrentMember()
{
    if (!m_teamCollection)
        return postError("Can't remove member to team: team collection is null");

    QList<QListWidgetItem *> selected = ui->lwTeamMembers->selectedItems();
    foreach(QListWidgetItem *item, selected) {
        if (!m_teamCollection->removeMember(m_converter.nameFromShortDescription(item->text()))) {
            postWarning(QString("Can't remove member from team: %1").arg(m_teamCollection->lastError()));
            continue;
        }
    }

    return true;
}

void TeamMembersWidget::notifyError(const QString &text) const
{
    QMessageBox::critical(nullptr,
                         "Error",
                         text
                         );
}

void TeamMembersWidget::notifyWarning(const QString &text) const
{
    QMessageBox::warning(nullptr,
                         "Warning",
                         text
                         );
}

void TeamMembersWidget::editItem(QListWidgetItem *item)
{
    if (!item) {
        postError("Can't edit null item");
        return;
    }

    if (!m_teamCollection) {
        postError("Can't edit item: team collection hasn't been set");
        return;
    }

    if (!m_pawnEditor) {
        postError("Can't edit item: pawn editor hasn't been set");
        return;
    }

    Pawn oldMember = m_converter.itemToPawn(m_teamCollection, item);
    if (oldMember.isNull()) {
        postError(m_converter.lastError());
        return;
    }

    m_pawnEditor->setMode(PawnEditor::EditTeamMember);
    if (m_pawnEditor->execEditor(oldMember) == QDialog::Rejected)
        return;

    // Accepted
    if (!m_teamCollection->setMember(oldMember.name(), m_pawnEditor->getMember())){
        postError(QString("Can't save team member: %1").arg(m_teamCollection->lastError()));
        return;
    }

    // List will be updated by team collection signals
}

void TeamMembersWidget::onTeamMemberAdded(Pawn member)
{
    ui->lwTeamMembers->addItem(m_converter.pawnToItem(member));
}

void TeamMembersWidget::onTeamMemberRemoved(Pawn member)
{
    foreach(QListWidgetItem *item, ui->lwTeamMembers->findItems(m_converter.toShortDescription(member), Qt::MatchExactly))
        delete item;
}

void TeamMembersWidget::onTeamMemberChanged(Pawn oldMember, Pawn newMember)
{
    foreach(QListWidgetItem *item, ui->lwTeamMembers->findItems(m_converter.toShortDescription(oldMember), Qt::MatchExactly))
        m_converter.updateItem(item, newMember);
}

void TeamMembersWidget::onDestroyed(QObject *obj)
{
    if (obj == m_teamCollection)
        m_teamCollection = nullptr;

    if (obj == m_pawnEditor)
        m_pawnEditor = nullptr;
}
