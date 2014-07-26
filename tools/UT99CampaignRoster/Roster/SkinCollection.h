#ifndef SKINCOLLECTION_H
#define SKINCOLLECTION_H

#include "RosterObject.h"

#include "RosterContainer.h"

class PawnSkin;

class SkinCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit SkinCollection(QObject *parent = 0);

    PawnSkin *getSkin(const QString &name);

    QList<PawnSkin *> allSkins() const;

signals:

public slots:

private:
    RosterContainer m_skins;

};

#endif // SKINCOLLECTION_H
