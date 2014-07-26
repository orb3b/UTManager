#include "PawnEditor.h"
#include "ui_PawnEditor.h"

#include <QMessageBox>

#include "Logs.h"
#include "Roster/MaterialCollection.h"
#include "Roster/ClassCollection.h"
#include "Roster/SkinCollection.h"
#include "Roster/FaceCollection.h"
#include "Roster/PawnClass.h"
#include "Roster/PawnSkin.h"
#include "Roster/PawnFace.h"

PawnEditor::PawnEditor(QWidget *parent) :
    QDialog(parent),
    RosterComponent(),
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

    // Ui - Material Combo boxes
    connect(ui->cbClasses, SIGNAL(currentIndexChanged(QString)), SLOT(onCurrentClassChanged(QString)), Qt::QueuedConnection);
    connect(ui->cbSkins, SIGNAL(currentIndexChanged(QString)), SLOT(onCurrentSkinChanged(QString)), Qt::QueuedConnection);

    // Change Ui according to editor's mode
    changeUi();
}

PawnEditor::~PawnEditor()
{
    delete ui;
}

void PawnEditor::setMaterialCollection(MaterialCollection *collection)
{
    m_materialCollection = collection;

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
    if (m_materialCollection.isNull())
        return;

    fillClasses();
}

void PawnEditor::setCurrentClass(PawnClass *current)
{
    m_currentClass = current;

    fillSkins();
}

void PawnEditor::setCurrentSkin(PawnSkin *current)
{
    m_currentSkin = current;

    fillFaces();
}

void PawnEditor::fillClasses()
{
    ui->cbClasses->clear();

    if (m_materialCollection.isNull())
        return;

    foreach(PawnClass *pawnClass, m_materialCollection->classCollection()->allClasses())
        ui->cbClasses->addItem(pawnClass->name());

    if (ui->cbClasses->count() > 0)
        ui->cbClasses->setCurrentIndex(0);

    // Skins will be updated by class's index change
}

void PawnEditor::fillSkins()
{
    ui->cbSkins->clear();

    if (m_currentClass.isNull())
        return;    

    foreach(PawnSkin *skin, m_currentClass->skinCollection()->allSkins())
        ui->cbSkins->addItem(skin->name());

    if (ui->cbSkins->count() > 0)
        ui->cbSkins->setCurrentIndex(0);

    // Faces will be updated by skin's index change
}

void PawnEditor::fillFaces()
{
    ui->cbFaces->clear();

    if (m_currentSkin.isNull())
        return;    

    foreach(PawnFace *face, m_currentSkin->faceCollection()->allFaces())
        ui->cbFaces->addItem(face->name());

    if (ui->cbFaces->count() > 0)
        ui->cbFaces->setCurrentIndex(0);
}

void PawnEditor::onCurrentClassChanged(const QString &name)
{
    if (m_materialCollection.isNull())
        return;

    PawnClass *current = m_materialCollection->classCollection()->getClass(name);
    if (!current) {
        postError(QString("Class %1 aren't exist").arg(name));
        return;
    }

    setCurrentClass(current);
}

void PawnEditor::onCurrentSkinChanged(const QString &name)
{
    if (m_currentClass.isNull())
        return;

    PawnSkin *current = m_currentClass->skinCollection()->getSkin(name);
    if (!current) {
        postError(QString("Skin %1 aren't exist").arg(name));
        return;
    }

    setCurrentSkin(current);
}
