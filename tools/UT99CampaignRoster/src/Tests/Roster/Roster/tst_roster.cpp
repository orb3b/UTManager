#include <QString>
#include <QtTest>

#include "Roster.h"

class tst_Roster : public QObject
{
    Q_OBJECT

public:
    tst_Roster();

private Q_SLOTS:
    void constructorAndMemberDestroyHandling();

    void destructor();
};

tst_Roster::tst_Roster()
{
}

void tst_Roster::constructorAndMemberDestroyHandling()
{
    QScopedPointer<Roster> roster(new Roster());

    QVERIFY(roster->materialCollection() != nullptr);
    delete roster->materialCollection();
    QVERIFY(roster->materialCollection() == nullptr);

    QVERIFY(roster->pawnCollection() != nullptr);
    delete roster->pawnCollection();
    QVERIFY(roster->pawnCollection() == nullptr);

    QVERIFY(roster->teamCollection() != nullptr);
    delete roster->teamCollection();
    QVERIFY(roster->teamCollection() == nullptr);
}

void tst_Roster::destructor()
{
    QScopedPointer<Roster> roster(new Roster());
    QPointer<MaterialCollection> materialCollection(roster->materialCollection());
    QPointer<PawnCollection> pawnCollection(roster->pawnCollection());
    QPointer<TeamCollection> teamCollection(roster->teamCollection());

    delete roster.take();

    QVERIFY(materialCollection.isNull());
    QVERIFY(pawnCollection.isNull());
    QVERIFY(teamCollection.isNull());
}

QTEST_APPLESS_MAIN(tst_Roster)

#include "tst_roster.moc"
