#include "MainView.h"
#include "ui_MainView.h"

#include "ProjectView.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // Menu bar action connections
    connect(ui->actionOpenProject, SIGNAL(triggered(bool)), SLOT(onActionOpenProject(bool)));
    // log menu
    connect(ui->actionShowLog, SIGNAL(triggered()), SLOT(onActionShowLog()));

#ifdef DEBUG
    m_logView.setGeometry(7, 30, m_logView.width(), m_logView.height());
    onActionShowLog();
#endif
}

MainView::~MainView()
{
    delete ui;
    m_logView.close();
}

void MainView::closeEvent(QCloseEvent *event)
{
    m_logView.close();
    event->accept();
}

void MainView::onActionOpenProject(bool)
{
    //ui->menuFile->insertAction();
    sLogMsg << "MainView::onActionOpenProject";
    m_provider.openProject(QString("blabla"));

    setCentralWidget(new ProjectView(&m_provider, this));
}

void MainView::onActionShowSettings()
{
}

void MainView::onActionShowLog()
{
    m_logView.show();
}
