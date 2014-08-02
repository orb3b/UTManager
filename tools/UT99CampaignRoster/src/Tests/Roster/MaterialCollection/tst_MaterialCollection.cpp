#include <QString>
#include <QtTest>

#include "MaterialCollection.h"
#include "ClassCollection.h"

class tst_MaterialCollection : public QObject
{
    Q_OBJECT

public:
    tst_MaterialCollection();

private Q_SLOTS:
    void consistency();
};

tst_MaterialCollection::tst_MaterialCollection()
{
}

void tst_MaterialCollection::consistency()
{
    MaterialCollection materials;

    QVERIFY(materials.isConsistent());

    ClassCollection *classCollection =  materials.classCollection();
    delete classCollection;
    QVERIFY(!materials.isConsistent());
}

QTEST_APPLESS_MAIN(tst_MaterialCollection)

#include "tst_MaterialCollection.moc"
