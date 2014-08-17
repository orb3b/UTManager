#include <QString>
#include <QtTest>

#include "MaterialCollection.h"
#include "ClassCollection.h"
#include "WeaponCollection.h"

class tst_MaterialCollection : public QObject
{
    Q_OBJECT

public:
    tst_MaterialCollection();

private Q_SLOTS:
    void consistency();
    void classCollection();
    void weaponCollection();
};

tst_MaterialCollection::tst_MaterialCollection()
{
}

void tst_MaterialCollection::consistency()
{
    MaterialCollection materials;

    QVERIFY(materials.isConsistent());
}

void tst_MaterialCollection::classCollection()
{
    MaterialCollection materials;

    ClassCollection *classCollection =  materials.classCollection();
    delete classCollection;
    QVERIFY(!materials.isConsistent());
}

void tst_MaterialCollection::weaponCollection()
{
    MaterialCollection materials;

    WeaponCollection *weaponCollection = materials.weaponCollection();
    delete weaponCollection;
    QVERIFY(!materials.isConsistent());
}

QTEST_APPLESS_MAIN(tst_MaterialCollection)

#include "tst_MaterialCollection.moc"
