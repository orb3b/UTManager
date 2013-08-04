#include "PlayerDelegate.h"
#include "PlayerDelegateEditor.h"
#include <DataProvider/Entity/UTEntity.h>

#include <QVariant>
#include <QPainter>

PlayerDelegate::PlayerDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *PlayerDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    return new PlayerDelegateEditor(0);
}

void PlayerDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    PlayerDelegateEditor *playerEditor = qobject_cast<PlayerDelegateEditor*>(editor);
    if (!playerEditor)
        return;

    QVariant data = index.model()->data(index);
    if (!data.canConvert<UTEntity>()){
        sLogErr << "PlayerDelegate::setEditorData cannot convert to UTEntity";
        return;
    }

    playerEditor->setPlayerEntity(data.value<UTEntity>());
}

void PlayerDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    Q_UNUSED(editor)
    Q_UNUSED(model)
    Q_UNUSED(index)
}

void PlayerDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)

    editor->setGeometry(option.rect);
}

void PlayerDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant data = index.model()->data(index);
    if (!data.canConvert<UTEntity>()){
        sLogErr << "PlayerDelegate::paint cannot convert to UTEntity";
        return;
    }

    UTEntity entity = data.value<UTEntity>();

    painter->save();

    painter->drawText(option.rect, Qt::AlignCenter, entity.name());

    painter->restore();
}

QSize PlayerDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    PlayerDelegateEditor playerEditor;

    QVariant data = index.model()->data(index);
    if (!data.canConvert<UTEntity>()){
        sLogErr << "PPlayerDelegate::sizeHint cannot convert to UTEntity";
        return QSize(0,0);
    }

    playerEditor.setPlayerEntity(data.value<UTEntity>());

    QSize sz = playerEditor.size();

    return sz;
//    QSize size = index.data(Qt::SizeHintRole).toSize();
//    if (size.isValid()) {
//        return size;
//    } else {

//    }
}
