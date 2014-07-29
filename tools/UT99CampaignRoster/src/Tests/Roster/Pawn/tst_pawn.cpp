#include <QString>
#include <QtTest>

#include "Pawn.h"

class tst_Pawn : public QObject
{
    Q_OBJECT

public:
    tst_Pawn();

private Q_SLOTS:
    void setName_Normal();
    void setName_Empty();
    void setName_Same();
};

tst_Pawn::tst_Pawn()
{
}

void tst_Pawn::setName_Normal()
{
    Pawn p;

    p.setName("MyName");

    QCOMPARE(p.name(), QString("MyName"));
    QVERIFY(p.changed());
}

void tst_Pawn::setName_Empty()
{
    Pawn g;

    g.setName("");

    QCOMPARE(g.name(), QString());
    QVERIFY(g.changed());
}

void tst_Pawn::setName_Same()
{
    Pawn p;
    QString oldName = p.name();

    p.setName(p.name());

    QCOMPARE(p.name(), oldName);
    QVERIFY(!p.changed());
}


QTEST_APPLESS_MAIN(tst_Pawn)

#include "tst_pawn.moc"
