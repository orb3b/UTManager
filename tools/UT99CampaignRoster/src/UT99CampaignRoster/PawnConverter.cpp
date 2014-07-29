#include "PawnConverter.h"

#include <QListWidgetItem>

#include "Roster/PawnGroup.h"

PawnConverter::PawnConverter(QObject *parent) :
    RosterObject(parent)
{
}

QString PawnConverter::nameFromShortDescription(const QString &description) const
{
    clearError();

    QString result = description;
    if (result.endsWith("*"))
        result = result.left(result.size() - 1);

    int pos = result.indexOf("_");
    if (pos < 0)
        return result;

    return result.right(result.size() - pos - 1);
}

QString PawnConverter::toShortDescription(const Pawn &member) const
{
    clearError();

    return QString("%1_%2%3")
            .arg(member.lives())
            .arg(member.name())
            .arg(member.changed() ? "*" : "");
}

QColor PawnConverter::teamColor(const Pawn &member) const
{
    switch(member.team()) {
    case Pawn::Red:
        return QColor(Qt::red);
    case Pawn::Blue:
        return QColor(Qt::blue);
    case Pawn::Green:
        return QColor(Qt::green);
    case Pawn::Gold:
        return QColor(Qt::darkYellow);
    default:
        return QColor(Qt::black);
    }

    return QColor(Qt::black);
}

QListWidgetItem *PawnConverter::pawnToItem(const Pawn &pawn)
{
    if (pawn.isNull()) {
        postError("Can't convert pawn to item: pawn is null");
        return nullptr;
    }

    QListWidgetItem *item = new QListWidgetItem();

    if (!updateItem(item, pawn))
        return nullptr;

    postSuccess(QString("Convertion Pawn %1 to item have been successfull").arg(pawn.name()));

    return item;
}

Pawn PawnConverter::itemToPawn(const PawnGroup *group, const QListWidgetItem *item)
{
    if (!group) {
        postError("Invalid group selected!");
        return Pawn::Null();;
    }

    if (!item) {
        postError("Invalid item selected");
        return Pawn::Null();
    }

    Pawn member = group->getMember(nameFromShortDescription(item->text()));
    if (member.isNull())
        postError(QString("Can't find member for item %1").arg(item->text()));

    return member;
}

bool PawnConverter::updateItem(QListWidgetItem *item, const Pawn &pawn)
{
    if (!item)
        return postError("Can't update item: item is null");

    if (pawn.isNull())
        return postError("Can't update item: pawn is null");

    item->setText(toShortDescription(pawn));
    item->setForeground(QBrush(teamColor(pawn)));

    return postSuccess(QString("Item %1 have been updated successfully").arg(item->text()));
}

