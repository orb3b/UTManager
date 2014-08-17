#ifndef PAWNCLASS_H
#define PAWNCLASS_H

#include "Material.h"

class SkinCollection;

class ROSTER_EXPORT PawnClass : public Material
{
    Q_OBJECT
public:
    explicit PawnClass(QObject *parent = 0);
    ~PawnClass();

    SkinCollection *skinCollection();

signals:

public slots:

private:
    void createSkinCollection();
    void deleteSkinCollection();

private slots:
    void onMemberDestroyed(QObject *obj);

private:
    SkinCollection *m_skinCollection;

};

#endif // PAWNCLASS_H
