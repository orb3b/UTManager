#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>
#include <QHBoxLayout>

#include "Logs.h"

#include "PawnGroupsWidget.h"
#include "TeamMembersWidget.h"
#include "InteractionWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    RosterComponent(),
    ui(new Ui::MainWindow),
    m_pawnGroupsWidget(nullptr),
    m_teamMembersWidget(nullptr),
    m_interactionWidget(nullptr),
    m_pawnEditor(nullptr)
{
    ui->setupUi(this);

    // Application icon
    QApplication::setWindowIcon(this->windowIcon());

    // Configure roster
    m_roster = new Roster();

    // Ui - Editors
    m_pawnEditor = new PawnEditor(this);

    // Ui - components widgets
    m_pawnGroupsWidget = new PawnGroupsWidget(this);
    m_pawnGroupsWidget->setPawnEditor(m_pawnEditor);
    m_pawnGroupsWidget->setPawnCollection(m_roster->pawnCollection());

    m_teamMembersWidget = new TeamMembersWidget(this);
    m_teamMembersWidget->setPawnEditor(m_pawnEditor);
    m_teamMembersWidget->setTeamCollection(m_roster->teamCollection());

    m_interactionWidget = new InteractionWidget(this);
    connect(m_interactionWidget, SIGNAL(addPawnToTeam()), SLOT(addPawnToTeam()));
    connect(m_interactionWidget, SIGNAL(removePawnFromTeam()), SLOT(removePawnFromTeam()));

    // Ui - central widget
    QHBoxLayout *layout = new QHBoxLayout();

    layout->addWidget(m_pawnGroupsWidget);
    layout->addWidget(m_interactionWidget);
    layout->addWidget(m_teamMembersWidget);

    centralWidget()->setLayout(layout);

    // Ui -> Actions
    ui->actionOpen->setShortcut(QKeySequence(tr("Ctrl+O")));

    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(openProject()));
    connect(ui->actionGenerate_Unreal_ini, SIGNAL(triggered()), m_roster->teamCollection(), SLOT(exportToIni()));

    connect(ui->actionQuit, SIGNAL(triggered()), SLOT(close()));

    openProject();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_roster;
}

void MainWindow::notifyError(const QString &text) const
{
    QMessageBox::critical(nullptr,
                         "Error",
                         text
                         );
}

void MainWindow::notifyWarning(const QString &text) const
{
    QMessageBox::warning(nullptr,
                         "Warning",
                         text
                         );
}

void MainWindow::openProject()
{
    if (!m_roster->openProject("Project.ini"))
        postError(QString("Can't open project: %1").arg(m_roster->pawnCollection()->lastError()));
}

void MainWindow::addPawnToTeam()
{
    foreach(const Pawn& member, m_pawnGroupsWidget->getSelectedPawns())
        m_teamMembersWidget->addMember(member);
}

void MainWindow::removePawnFromTeam()
{
    m_teamMembersWidget->removeCurrentMember();
}
