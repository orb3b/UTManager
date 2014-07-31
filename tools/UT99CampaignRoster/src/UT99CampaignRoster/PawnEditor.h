#ifndef PAWNEDITOR_H
#define PAWNEDITOR_H

#include <QDialog>
#include "Roster/RosterComponent.h"

#include <QPointer>

#include "Roster/Pawn.h"

namespace Ui {
class PawnEditor;
}

class QAbstractSpinBox;
class QAbstractSlider;
class QDoubleSpinBox;

class MaterialCollection;
class PawnClass;
class PawnSkin;

class PawnEditor : public QDialog,
                   public RosterComponent
{
    Q_OBJECT
public:
    enum EditorMode {
        EditGroupMember,
        EditTeamMember
    };

public:
    PawnEditor(QWidget *parent = 0);
    ~PawnEditor();

    // Material collection for pawn editor
    void setMaterialCollection(MaterialCollection *collection);

    Pawn getMember() const;

    EditorMode mode() const;
    void setMode(EditorMode newMode);

public slots:
    int execEditor(const Pawn &getMember);

protected:
    virtual void notifyError(const QString &text) const OVERWRITE;
    virtual void notifyWarning(const QString &text) const OVERWRITE;

private:
    void changeUi();
    void fillUi(const Pawn &getMember);

    void connectSliderAndSpinBox(QAbstractSlider *slider, QAbstractSpinBox *spinBox);
    void connectSliderAndDoubleSpinBox(QAbstractSlider *slider, QDoubleSpinBox *spinBox);

private slots:
    // Fill's materials
    void fillMaterials();    

    void fillClasses();
    void fillSkins();
    void fillFaces();

    void setCurrentClass(PawnClass *current);
    void setCurrentSkin(PawnSkin *current);

    void onCurrentClassChanged(const QString &name);
    void onCurrentSkinChanged(const QString &name);

private:
    Ui::PawnEditor *ui;
    EditorMode m_mode;

    QPointer<MaterialCollection> m_materialCollection;
    QPointer<PawnClass> m_currentClass;
    QPointer<PawnSkin> m_currentSkin;
};

#endif // PAWNEDITOR_H
