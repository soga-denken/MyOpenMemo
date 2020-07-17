#include <QtTest>

// add necessary includes here

class FirstTest : public QObject
{
    Q_OBJECT

public:
    FirstTest();
    ~FirstTest();

private slots:
    // 自動で追加されたスロット。初期化に利用
    void initTestCase();
    // きれいにする
    void cleanupTestCase();

    // TESTケースはslotに保存。名前は自由っぽい。
    void test_case1();

};

FirstTest::FirstTest()
{

}

FirstTest::~FirstTest()
{

}

void FirstTest::initTestCase()
{

}

void FirstTest::cleanupTestCase()
{

}

void FirstTest::test_case1()
{
    QVERIFY(false);
}

// QTEST_MAINもあるらしい。
QTEST_APPLESS_MAIN(FirstTest)

// このincludeが必要な場合は、宣言と実装が同じファイルにある場合
#include "tst_firsttest.moc"
