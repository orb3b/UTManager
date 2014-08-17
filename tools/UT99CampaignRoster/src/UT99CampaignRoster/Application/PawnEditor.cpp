#include "PawnEditor.h"
#include "ui_PawnEditor.h"

#include <QMessageBox>

#include <Logs.h>
#include <MaterialCollection.h>
#include <ClassCollection.h>
#include <SkinCollection.h>
#include <FaceCollection.h>
#include <PawnClass.h>
#include <PawnSkin.h>
#include <PawnFace.h>

#include "EditorConnector.h"

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
    ui->cbTeam->addItem(tr("None"), QVariant::fromValue(Pawn::None));
    ui->cbTeam->addItem(tr("Red"), QVariant::fromValue(Pawn::Red));
    ui->cbTeam->addItem(tr("Blue"), QVariant::fromValue(Pawn::Blue));
    ui->cbTeam->addItem(tr("Green"), QVariant::fromValue(Pawn::Green));
    ui->cbTeam->addItem(tr("Gold"), QVariant::fromValue(Pawn::Gold));

    // Ui - Material Combo boxes
    connect(ui->cbClasses, SIGNAL(currentIndexChanged(QString)), SLOT(onCurrentClassChanged(QString)), Qt::QueuedConnection);
    connect(ui->cbSkins, SIGNAL(currentIndexChanged(QString)), SLOT(onCurrentSkinChanged(QString)), Qt::QueuedConnection);

    // Ui - Skill adjust group
    ui->hsSkillAdjust->setMinimum(Pawn::MIN_SKILL_ADJUST);
    ui->hsSkillAdjust->setMaximum(Pawn::MAX_SKILL_ADJUST);
    ui->hsSkillAdjust->setSingleStep(1);
    ui->hsSkillAdjust->setPageStep(1);

    ui->sbSkillAdjust->setMinimum(Pawn::MIN_SKILL_ADJUST);
    ui->sbSkillAdjust->setMaximum(Pawn::MAX_SKILL_ADJUST);
    ui->sbSkillAdjust->setSingleStep(1);

    connectSliderAndSpinBox(ui->hsSkillAdjust, ui->sbSkillAdjust);

    // Ui - Accuracy group
    ui->dspAccuracy->setMinimum(Pawn::MIN_ACCURACY);
    ui->dspAccuracy->setMaximum(Pawn::MAX_ACCURACY);
    ui->dspAccuracy->setSingleStep(0.01);

    connectSliderAndDoubleSpinBox(ui->hsAccuracy, ui->dspAccuracy);

    // Ui - Alertness group
    ui->dspAlertness->setMinimum(Pawn::MIN_ALERTNESS);
    ui->dspAlertness->setMaximum(Pawn::MAX_ALERTNESS);
    ui->dspAlertness->setSingleStep(0.01);

    connectSliderAndDoubleSpinBox(ui->hsAlertness, ui->dspAlertness);

    // Ui - Camping group
    ui->dspCamping->setMinimum(Pawn::MIN_CAMPING);
    ui->dspCamping->setMaximum(Pawn::MAX_CAMPING);
    ui->dspCamping->setSingleStep(0.01);

    connectSliderAndDoubleSpinBox(ui->hsCamping, ui->dspCamping);

    // Ui - Strafing Agility group
    ui->dspStrafingAgility->setMinimum(Pawn::MIN_STRAFING_AGILITY);
    ui->dspStrafingAgility->setMaximum(Pawn::MAX_STRAFING_AGILITY);
    ui->dspStrafingAgility->setSingleStep(0.01);

    connectSliderAndDoubleSpinBox(ui->hsStrafingAgility, ui->dspStrafingAgility);

    // Ui - Combat Style group
    ui->cbCombatStyle->addItem(tr("Normal"), QVariant::fromValue(Pawn::Normal));
    ui->cbCombatStyle->addItem(tr("Agressive"), QVariant::fromValue(Pawn::Aggressive));
    ui->cbCombatStyle->addItem(tr("Berserk"), QVariant::fromValue(Pawn::Berserk));
    ui->cbCombatStyle->addItem(tr("Cautious"), QVariant::fromValue(Pawn::Cautious));
    ui->cbCombatStyle->addItem(tr("Avoidant"), QVariant::fromValue(Pawn::Avoidant));

    // Ui - Jumpy group

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
    member.setTeam(ui->cbTeam->currentData().value<Pawn::Team>());
    member.setLives(ui->sbLives->value());

    member.setSkillAdjust(ui->sbSkillAdjust->value());

    member.setAccuracy(ui->dspAccuracy->value());
    member.setAlertness(ui->dspAlertness->value());
    member.setCamping(ui->dspCamping->value());
    member.setStrafingAgility(ui->dspStrafingAgility->value());
    member.setCombatStyle(ui->cbCombatStyle->currentData().value<Pawn::CombatStyle>());
    member.setJumpy(ui->chbJumpy->isChecked());

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

    ui->sbSkillAdjust->setValue(member.skillAdjust());

    ui->dspAccuracy->setValue(member.accuracy());
    ui->dspAlertness->setValue(member.alertness());
    ui->dspCamping->setValue(member.camping());
    ui->dspStrafingAgility->setValue(member.strafingAgility());
    ui->cbCombatStyle->setCurrentIndex(ui->cbCombatStyle->findData(member.combatStyle()));
    ui->chbJumpy->setChecked(member.jumpy());
}

void PawnEditor::connectSliderAndSpinBox(QAbstractSlider *slider, QAbstractSpinBox *spinBox)
{
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
}

void PawnEditor::connectSliderAndDoubleSpinBox(QAbstractSlider *slider, QDoubleSpinBox *spinBox)
{
    // Create new EditorConnector and attach it to this widget (look at this)
    EditorConnector *connector = new EditorConnector(this);
    connector->setup(slider, spinBox, 100);
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
