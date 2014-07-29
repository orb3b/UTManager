#include "InteractionWidget.h"
#include "ui_InteractionWidget.h"

InteractionWidget::InteractionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InteractionWidget)
{
    ui->setupUi(this);

    // Ui - buttons
    connect(ui->btnAddPawnToTeam, SIGNAL(clicked()), SIGNAL(addPawnToTeam()));
    connect(ui->btnRemovePawnFromTeam, SIGNAL(clicked()), SIGNAL(removePawnFromTeam()));
}

InteractionWidget::~InteractionWidget()
{
    delete ui;
}
