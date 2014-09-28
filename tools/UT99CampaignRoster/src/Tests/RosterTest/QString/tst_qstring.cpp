#include <QString>
#include <QtTest>

#include <QDebug>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//#define GMOCK_BEGIN \
//{ \
//    try \
//    {

//#define GMOCK_END \
//    } catch (...) { \
//        QFAIL("Caught google mock exeption!"); \
//    } \
//}

#define GMOCK_BEGIN \
try \

#define GMOCK_END \
catch (...) { \
    QFAIL("Caught google mock exeption!"); \
} \

using ::testing::AtLeast;

class ITurtle
{
public:
    virtual void Foo() = 0;
};

class MockTurtle : public ITurtle
{
public:
    MOCK_METHOD0(Foo, void());
};

class tst_QString : public QObject
{
    Q_OBJECT

public:
    tst_QString();

private Q_SLOTS:
    void toUpper_data();
    void toUpper();

    void gmockTest();

    void myTest();
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

void tst_QString::gmockTest()
{
    GMOCK_BEGIN
    {
        MockTurtle turtle;
        EXPECT_CALL(turtle, Foo())
            .Times(AtLeast(1));

        turtle.Foo();
    }
    GMOCK_END
}

//{
//GMOCK_BEGIN
//    MockTurtle turtle;
//    EXPECT_CALL(turtle, Foo())
//        .Times(AtLeast(1));

//GMOCK_END

//}

void tst_QString::myTest()
{
    QVERIFY(true);
}

//QTEST_APPLESS_MAIN(tst_QString)
int main(int argc, char *argv[])
{
    // The following line causes Google Mock to throw an exception on failure,
    // which will be interpreted by your testing framework as a test failure.
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);

    tst_QString tc;
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_qstring.moc"
