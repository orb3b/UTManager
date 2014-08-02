#include <QString>
#include <QtTest>

#include "RosterDataProvider.h"
#include "MaterialCollection.h"

class tst_RosterDataProvider : public QObject
{
    Q_OBJECT

public:
    tst_RosterDataProvider();

private Q_SLOTS:
    void consistency();
};

tst_RosterDataProvider::tst_RosterDataProvider()
{
}

void tst_RosterDataProvider::consistency()
{
    RosterDataProvider provider;

    QVERIFY(!provider.isConsistent());

    QScopedPointer<MaterialCollection> collection(new MaterialCollection());

    provider.setMaterialCollection(collection.data());
    QVERIFY(provider.isConsistent());

    delete collection.take();
    QVERIFY(!provider.isConsistent());
}

QTEST_APPLESS_MAIN(tst_RosterDataProvider)

#include "tst_RosterDataProvider.moc"
