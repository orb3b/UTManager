#include <QString>
#include <QtTest>

class tst_QString : public QObject
{
    Q_OBJECT

public:
    tst_QString();

private Q_SLOTS:
    void toUpper_data();
    void toUpper();
};

tst_QString::tst_QString()
{
}

void tst_QString::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void tst_QString::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

QTEST_APPLESS_MAIN(tst_QString)

#include "tst_qstring.moc"
