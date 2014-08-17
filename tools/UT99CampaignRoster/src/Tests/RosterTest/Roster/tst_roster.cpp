#include <QString>
#include <QtTest>

#include "Roster.h"

class tst_Roster : public QObject
{
    Q_OBJECT

public:
    tst_Roster();

private Q_SLOTS:
    void constructor();

    void pawnCollection();
    void teamCollection();
    void materialCollection();

    void destructor();
};

tst_Roster::tst_Roster()
{
}

void tst_Roster::constructor()
{
    QScopedPointer<Roster> roster(new Roster());

    QVERIFY(roster->materialCollection() != nullptr);
    QVERIFY(roster->pawnCollection() != nullptr);
    QVERIFY(roster->teamCollection() != nullptr);
}

void tst_Roster::pawnCollection()
{
    QScopedPointer<Roster> roster(new Roster());

    delete roster->pawnCollection();
    QVERIFY(roster->pawnCollection() == nullptr);
    QVERIFY(!roster->isConsistent());
}

void tst_Roster::teamCollection()
{
    QScopedPointer<Roster> roster(new Roster());

    delete roster->teamCollection();
    QVERIFY(roster->teamCollection() == nullptr);
    QVERIFY(!roster->isConsistent());
}

void tst_Roster::materialCollection()
{
    QScopedPointer<Roster> roster(new Roster());

    delete roster->materialCollection();
    QVERIFY(roster->materialCollection() == nullptr);
    QVERIFY(!roster->isConsistent());
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
