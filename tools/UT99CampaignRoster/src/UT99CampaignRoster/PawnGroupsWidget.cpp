#include "PawnGroupsWidget.h"
#include "ui_PawnGroupsWidget.h"

#include <QMessageBox>

#include "Roster/PawnCollection.h"
#include "PawnEditor.h"

PawnGroupsWidget::PawnGroupsWidget(QWidget *parent) :
    QWidget(parent),
    RosterComponent(),
    ui(new Ui::PawnGroupsWidget),
    m_pawnCollection(nullptr),
    m_pawnEditor(nullptr)
{
    ui->setupUi(this);

    // Ui - combo boxes
    connect(ui->cbPawnGroups, SIGNAL(currentIndexChanged(int)), SLOT(loadCurrentGroupMembers()));

    // Ui - lists
    connect(ui->lwPawnGroupMembers, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(editItem(QListWidgetItem*)));
}

PawnGroupsWidget::~PawnGroupsWidget()
{
    delete ui;
}

void PawnGroupsWidget::setPawnCollection(PawnCollection *collection)
{
    if (m_pawnCollection) {
        disconnect(m_pawnCollection, SIGNAL(groupAdded(QString)), this, SLOT(onGroupAdded(QString)));
        disconnect(m_pawnCollection, SIGNAL(groupRemoved(QString)), this, SLOT(onGroupRemoved(QString)));
        disconnect(m_pawnCollection, SIGNAL(groupChanged(QString)), this, SLOT(onGroupChanged(QString)));

        disconnect(m_pawnCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    }

    m_pawnCollection = collection;

    connect(m_pawnCollection, SIGNAL(groupAdded(QString)), SLOT(onGroupAdded(QString)), Qt::QueuedConnection);
    connect(m_pawnCollection, SIGNAL(groupRemoved(QString)), SLOT(onGroupRemoved(QString)), Qt::QueuedConnection);
    connect(m_pawnCollection, SIGNAL(groupChanged(QString)), SLOT(onGroupChanged(QString)), Qt::QueuedConnection);

    connect(m_pawnCollection, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)));
}

void PawnGroupsWidget::setPawnEditor(PawnEditor *editor)
{
    if (m_pawnEditor) {
        disconnect(m_pawnEditor, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    }

    m_pawnEditor = editor;

    connect(m_pawnEditor, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)));
}

QList<Pawn> PawnGroupsWidget::getSelectedPawns()
{
    clearError();

    QList<QListWidgetItem *> selected = ui->lwPawnGroupMembers->selectedItems();
    if (selected.isEmpty()) {
        postError("MainWindow::onMovePawnToTeamClicked member wasn't selected!");
        return QList<Pawn>();
    }

    PawnGroup *group = getCurrentGroup();
    if (!group) // Error occured, message & text already set, so return
        return QList<Pawn>();

    QList<Pawn> result;
    foreach (QListWidgetItem *item, selected) {
        Pawn member = m_converter.itemToPawn(group, item);
        if (member.isNull()) {
            postWarning(QString("Item %1 conversion to pawn failed with error: %2").arg(item->text(), m_converter.lastError()));
            continue;
        }

        result.append(member);
    }

    return result;
}

PawnGroup *PawnGroupsWidget::getCurrentGroup()
{
    clearError();

    if (!m_pawnCollection) {
        postError("Can't get current group: pawn collection haven't been set");
        return nullptr;
    }

    QString groupName = ui->cbPawnGroups->currentText();
    PawnGroup *group = m_pawnCollection->getGroup(groupName);
    if (!group) {
        postError(QString("Group with name %1 didn't exist").arg(groupName));
        return nullptr;
    }

    return group;
}

void PawnGroupsWidget::notifyError(const QString &text) const
{
    QMessageBox::critical(nullptr,
                         "Error",
                         text
                         );
}

void PawnGroupsWidget::notifyWarning(const QString &text) const
{
    QMessageBox::warning(nullptr,
                         "Warning",
                         text
                         );
}

void PawnGroupsWidget::loadCurrentGroupMembers()
{
    PawnGroup *group = getCurrentGroup();
    if (!group)
        return;

    ui->lwPawnGroupMembers->clear();

    foreach(const Pawn &member, group->allMembers()) {
        QListWidgetItem *item = m_converter.pawnToItem(member);
        if (!item) {
            postWarning(QString("Can't convert pawn %1 to item").arg(m_converter.lastError()));
            continue;
        }

        ui->lwPawnGroupMembers->addItem(item);
    }
}

void PawnGroupsWidget::editItem(QListWidgetItem *item)
{
    if (!item) {
        postError("Can't edit null item");
        return;
    }

    if (!m_pawnEditor) {
        postError("Can't edit item: pawn editor hasn't been set");
        return;
    }

    PawnGroup *currentGroup = getCurrentGroup();
    if (!currentGroup)
        return;

    Pawn oldMember = m_converter.itemToPawn(currentGroup, item);
    if (oldMember.isNull()) {
        postError(m_converter.lastError());
        return;
    }

    m_pawnEditor->setMode(PawnEditor::EditGroupMember);
    if (m_pawnEditor->execEditor(oldMember) == QDialog::Rejected)
        return;

    // Accepted
    if (!currentGroup->setMember(oldMember.name(), m_pawnEditor->getMember())){
        postError(QString("Can't save group %1 member: %2").arg(currentGroup->name(), currentGroup->lastError()));
        return;
    }

    loadCurrentGroupMembers();
}

void PawnGroupsWidget::onGroupAdded(QString groupName)
{
    ui->cbPawnGroups->addItem(groupName);
}

void PawnGroupsWidget::onGroupRemoved(QString groupName)
{
    ui->cbPawnGroups->removeItem(ui->cbPawnGroups->findText(groupName));
}

void PawnGroupsWidget::onGroupChanged(QString groupName)
{
    if (ui->cbPawnGroups->currentText() == groupName)
        loadCurrentGroupMembers();
}

void PawnGroupsWidget::onDestroyed(QObject *obj)
{
    if (obj == m_pawnCollection)
        m_pawnCollection = nullptr;

    if (obj == m_pawnEditor)
        m_pawnEditor = nullptr;
}
