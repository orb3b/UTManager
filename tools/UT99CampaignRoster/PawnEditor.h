#ifndef PAWNEDITOR_H
#define PAWNEDITOR_H

#include <QDialog>

#include "Roster/Pawn.h"

namespace Ui {
class PawnEditor;
}

class PawnEditor : public QDialog
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

    Pawn getMember() const;

    EditorMode mode() const;
    void setMode(EditorMode newMode);

public slots:
    int execEditor(const Pawn &getMember);

protected:
    virtual bool postError(const QString &text);

private:
    void changeUi();
    void fillUi(const Pawn &getMember);

private slots:

private:
    Ui::PawnEditor *ui;
    EditorMode m_mode;
};

#endif // PAWNEDITOR_H
