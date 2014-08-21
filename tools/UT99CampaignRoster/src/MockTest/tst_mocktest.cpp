#include <QString>
#include <QtTest>
#include <gtest/gtest.h>

namespace {
class QStringTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    QStringTest() {
      // You can do set-up work for each test here.
    }

    virtual ~QStringTest() {
      // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
      // Code here will be called immediately after the constructor (right
      // before each test).
    }

    virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for Foo.
};
}

TEST(QStringTest, QStringToUpper) {
    QString test("TeSt");

    ASSERT_TRUE(test.toUpper() == "TEST");
}

//class MockTest : public QObject
//{
//    Q_OBJECT

//public:
//    MockTest();

//private Q_SLOTS:
//    void testCase1();
//};

//MockTest::MockTest()
//{
//}

//void MockTest::testCase1()
//{
//    QVERIFY2(true, "Failure");
//}

//QTEST_APPLESS_MAIN(MockTest)

//#include "tst_mocktest.moc"
