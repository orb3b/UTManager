#ifndef PAWNCONVERTER_H
#define PAWNCONVERTER_H

#include "Roster/RosterObject.h"

#include "Roster/Pawn.h"

class QListWidgetItem;
class PawnGroup;

class PawnConverter : public RosterObject
{
    Q_OBJECT
public:
    explicit PawnConverter(QObject *parent = 0);

    // Converting pawn to/from QString (used for titles)
    QString nameFromShortDescription(const QString &description) const;
    QString toShortDescription(const Pawn &member) const;

    // Provides color for pawn
    QColor teamColor(const Pawn &member) const;

    // Converting QListWidgetItem to/from Pawn
    QListWidgetItem *pawnToItem(const Pawn &pawn);
    Pawn itemToPawn(const PawnGroup *group, const QListWidgetItem *item);
    bool updateItem(QListWidgetItem *item, const Pawn &pawn);

signals:

public slots:

};

#endif // PAWNCONVERTER_H
