#include "PawnEditor.h"
#include "ui_PawnEditor.h"

#include <QMessageBox>

#include "Logs.h"

PawnEditor::PawnEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PawnEditor),
    m_mode(EditTeamMember)
{
    ui->setupUi(this);

    // Ui - buttons
    connect(ui->btnSave, SIGNAL(clicked()), SLOT(accept()));
    connect(ui->btnCancel, SIGNAL(clicked()), SLOT(reject()));

    // Ui - Input
    // Ui - Team ComboBox
    ui->cbTeam->addItem("None", QVariant::fromValue((int)Pawn::None));
    ui->cbTeam->addItem("Red", QVariant::fromValue((int)Pawn::Red));
    ui->cbTeam->addItem("Blue", QVariant::fromValue((int)Pawn::Blue));
    ui->cbTeam->addItem("Green", QVariant::fromValue((int)Pawn::Green));
    ui->cbTeam->addItem("Gold", QVariant::fromValue((int)Pawn::Gold));

    // Change Ui according to editor's mode
    changeUi();
}

PawnEditor::~PawnEditor()
{
    delete ui;
}

Pawn PawnEditor::getMember() const
{
    Pawn member;

    member.setName(ui->leName->text());
    member.setTeam((Pawn::Team)ui->cbTeam->currentData().toInt());
    member.setLives(ui->sbLives->value());

    return member;
}

PawnEditor::EditorMode PawnEditor::mode() const
{
    return m_mode;
}

void PawnEditor::setMode(PawnEditor::EditorMode newMode)
{
    if (m_mode != newMode) {
        m_mode = newMode;
        changeUi();
    }
}

int PawnEditor::execEditor(const Pawn &member)
{
    fillUi(member);
    return exec();
}

void PawnEditor::changeUi()
{

}

void PawnEditor::fillUi(const Pawn &member)
{
    ui->leName->setText(member.name());

    ui->cbTeam->setCurrentIndex(ui->cbTeam->findData(member.team()));

    ui->sbLives->setValue(member.lives());
}

bool PawnEditor::postError(const QString &text)
{
    sLogErr << text;

    QMessageBox::warning(this,
                         tr("Error"),
                         text
                         );

    return false;
}
