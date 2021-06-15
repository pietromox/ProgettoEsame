#include <QtTest>
#include "QString"

// add necessary includes here

class unitTesting : public QObject
{
    Q_OBJECT

public:
    unitTesting();
    ~unitTesting();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();

};

QString labelString(int hour, int minutes, int seconds, QString &string){
    string.clear();


    if(hour < 10){
        string.append(QString::number(0));
        string.append(QString::number(hour));
    }
    else{
        string.append(QString::number(hour));
    }


    string.append(":");

    if(minutes <10){
        string.append(QString::number(0));
        string.append(QString::number(minutes));
    }
    else{
        string.append(QString::number(minutes));
    }
    string.append(":");
    if(seconds<10){
        string.append(QString::number(0));
        string.append(QString::number(seconds));
    }
    else{
        string.append(QString::number(seconds));

    }
    return string;
}


unitTesting::unitTesting()
{

}

unitTesting::~unitTesting()
{

}

void unitTesting::initTestCase()
{

}

void unitTesting::cleanupTestCase()
{

}

void unitTesting::test_case1()
{
    //expected to work fine

    QString string;

    QString testString=labelString(12,32,34,string);
    QVERIFY(testString=="12:32:34");

}

void unitTesting::test_case2() {

    //expected to work fine

    QString string;
    QString testString= labelString(2, 4, 5, string);
    QCOMPARE(testString, QString("02:04:05"));
}


void unitTesting::test_case3() {

    //expected to work fine

    QString string;
    QString testString= labelString(2, 14, 35, string);
    QCOMPARE(testString, QString("02:14:35"));
}

void unitTesting::test_case4() {

    //expected to work fine

    QString string;
    QString testString= labelString(12, 4, 35, string);
    QCOMPARE(testString, QString("12:04:35"));
}

void unitTesting::test_case5() {

    //expected to work fine

    QString string;
    QString testString= labelString(12,44,5, string);
    QCOMPARE(testString, QString("12:44:05"));
}

QTEST_APPLESS_MAIN(unitTesting)

#include "tst_unittesting.moc"
