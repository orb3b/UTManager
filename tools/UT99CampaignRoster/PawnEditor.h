#ifndef PAWNEDITOR_H
#define PAWNEDITOR_H

#include <QDialog>
#include "Roster/RosterComponent.h"

#include "Roster/Pawn.h"

namespace Ui {
class PawnEditor;
}

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

private slots:
    // Fill's materials
    void fillMaterials();

    void fillSkins(PawnClass *pawnClass);
    void fillFaces(PawnSkin *skin);

    // Handle deleting external components
    void onDestroyed(QObject *obj);

private:
    Ui::PawnEditor *ui;
    EditorMode m_mode;

    MaterialCollection *m_materialCollection;
};

#endif // PAWNEDITOR_H
