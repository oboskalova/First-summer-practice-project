#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../list.h"
#include "test.h"
class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void testCase1_data();
    void testCase1();
    void testCase4_data();
    void testCase4();
};

TestTest::TestTest()
{
}

void TestTest::testCase1_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<int>("expected");

    QTest::addColumn<int>("expected");


    QTest::newRow("t_length01") <<false<< 0;
    QTest::newRow("t_length02") <<true<< 5;

}

void TestTest::testCase1()
{
    test mc;
// length


    QFETCH(bool, first);
    QFETCH(int, expected);

    int actual = mc.t_length(first);
    QCOMPARE(actual, expected);


}

void TestTest::testCase4_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<bool>("expected");

    QTest::newRow("index01") <<1<< true;
    QTest::newRow("index02") <<6<<true;
    QTest::newRow("index02") <<-6<<true;


}


void TestTest::testCase4()
{
    test mc;
// []

    QFETCH(int, first);
    QFETCH(bool, expected);

   bool actual = mc.t_length(first);
    QCOMPARE(actual, expected);

}
QTEST_MAIN(TestTest)

#include "tst_testtest.moc"
