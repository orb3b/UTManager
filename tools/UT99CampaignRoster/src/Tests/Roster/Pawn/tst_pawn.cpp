#include <QString>
#include <QtTest>

#include "Pawn.h"

class tst_Pawn : public QObject
{
    Q_OBJECT

public:
    tst_Pawn();

private Q_SLOTS:
    void setName_data();
    void setName();
};

tst_Pawn::tst_Pawn()
{
}

void tst_Pawn::setName_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("result_name");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal name") << "MyName" << "MyName" << true;
    QTest::newRow("empty name") << "" << QString() << true;
    QTest::newRow1("same name") << Pawn().name() << Pawn().name() << false;
}

void tst_Pawn::setName()
{
    QFETCH(QString, name);
    QFETCH(QString, result_name);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setName(name);

    QCOMPARE(p.name(), result_name);
    QVERIFY(p.changed() == result_changed);
}

QTEST_APPLESS_MAIN(tst_Pawn)

#include "tst_pawn.moc"
