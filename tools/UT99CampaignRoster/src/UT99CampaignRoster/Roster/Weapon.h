#ifndef WEAPON_H
#define WEAPON_H

#include "Material.h"

class ROSTER_EXPORT Weapon : public Material
{
    Q_OBJECT
public:
    explicit Weapon(QObject *parent = 0);

signals:

public slots:

};

#endif // WEAPON_H
