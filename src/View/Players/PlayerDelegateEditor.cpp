#include "PlayerDelegateEditor.h"
#include "ui_PlayerDelegateEditor.h"

#include <QPixmap>

PlayerDelegateEditor::PlayerDelegateEditor(QWidget *parent) :
    UTEntityDelegateEditor(parent),
    ui(new Ui::PlayerDelegateEditor)
{
    ui->setupUi(this);
}

PlayerDelegateEditor::~PlayerDelegateEditor()
{
    delete ui;
}

void PlayerDelegateEditor::setPlayerEntity(const UTEntity &playerEntity)
{
    m_playerEntity = playerEntity;

    ui->lbName->setText(m_playerEntity.name());
    ui->lbPortrait->setPixmap(QPixmap(m_playerEntity.pathToImage()));
}
