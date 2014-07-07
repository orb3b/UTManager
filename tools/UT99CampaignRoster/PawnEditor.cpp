#include "PawnEditor.h"
#include "ui_PawnEditor.h"

#include <QMessageBox>

#include "Logs.h"

PawnEditor::PawnEditor(QWidget *parent) :
    QDialog(parent),
    RosterComponent(),
    ui(new Ui::PawnEditor),
    m_mode(EditTeamMember),
    m_materialCollection(nullptr)
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

void PawnEditor::setMaterialCollection(MaterialCollection *collection)
{
    if (m_materialCollection) {
        disconnect(m_materialCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    }

    m_materialCollection = collection;

    connect(m_materialCollection, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)));

    fillMaterials();
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

void PawnEditor::notifyError(const QString &text) const
{
    QMessageBox::critical(nullptr,
                         "Error",
                         text
                         );
}

void PawnEditor::notifyWarning(const QString &text) const
{
    QMessageBox::warning(nullptr,
                         "Warning",
                         text
                         );
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

void PawnEditor::fillMaterials()
{
    if (!m_materialCollection)
        return;

    if (m_materialCollection->classCollection()->size() < 1)
        return;

    ui->cbClasses->clear();

    foreach(PawnClass *pawnClass, m_materialCollection->classCollection()->allClasses())
        ui->cbClasses->addItem(pawnClass->description());

    fillSkins(m_materialCollection->classCollection()->first());
    fillFaces(m_materialCollection->classCollection()->first()->skinCollection());
}

void PawnEditor::fillSkins(PawnClass *pawnClass)
{
    if (!pawnClass)
        return;

    ui->cbSkins->clear();

    foreach(PawnSkin *skin, pawnClass->skinCollection()->all())
        ui->cbSkins->addItem(skin->description());
}

void PawnEditor::fillFaces(PawnSkin *skin)
{
    if (!skin)
        return;

    ui->cbFaces->clear();

    foreach(PawnFace *face, skin->faceCollection()->all())
        ui->cbSkins->addItem(face->description());
}

void PawnEditor::onDestroyed(QObject *obj)
{
    if (obj == m_materialCollection)
        m_materialCollection = nullptr;
}
