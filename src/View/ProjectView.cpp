#include "ProjectView.h"
#include "ui_ProjectView.h"

ProjectView::ProjectView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectView)
{
    ui->setupUi(this);
}

ProjectView::~ProjectView()
{
    delete ui;
}
