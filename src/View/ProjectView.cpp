#include "ProjectView.h"
#include "ui_ProjectView.h"

#include <DataProvider/UTDataProvider.h>
#include <DataProvider/Model/UTPlayerModel.h>

ProjectView::ProjectView(UTDataProvider *provider, QWidget *parent) :
    QWidget(parent),
    m_provider(provider),
    ui(new Ui::ProjectView)
{
    ui->setupUi(this);

    ui->lvPlayers->setModel(qobject_cast<QAbstractItemModel*>(m_provider->playerModel()));
    ui->lvPlayers->setItemDelegate(&m_playerDelegate);
}

ProjectView::~ProjectView()
{
    delete ui;
}
