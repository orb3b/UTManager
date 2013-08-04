#ifndef PLAYERDELEGATEEDITOR_H
#define PLAYERDELEGATEEDITOR_H

#include <QWidget>
#include <View/UTEntityDelegateEditor.h>

#include <DataProvider/Entity/UTEntity.h>

namespace Ui {
class PlayerDelegateEditor;
}

class PlayerDelegateEditor : public UTEntityDelegateEditor
{
    Q_OBJECT
    
public:
    explicit PlayerDelegateEditor(QWidget *parent = 0);
    ~PlayerDelegateEditor();
    
    void setPlayerEntity(const UTEntity& playerEntity);

private:
    Ui::PlayerDelegateEditor *ui;

    UTEntity m_playerEntity;
};

#endif // PLAYERDELEGATEEDITOR_H
