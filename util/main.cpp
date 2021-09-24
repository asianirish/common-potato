#include "gfunc.h"
#include "Test/TestA.h"
#include "Test/TestB.h"
#include "Test/TestC.h"

#include <menu/Console.h>
#include <menu/LineCommandTranslator.h>

#include <util/CuteFactory.h>
#include <util/Factory.h>
#include <util/LazyPointer.h>

#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include <QObject>

template<class T, int I>
class TestT
{
public:
    static const int INDEX = I;

    TestT() : _index(INDEX) {

    }

    void setData(const QList<T> &data) {
        _data = data;
    }

    T value() {
        return _data.at(_index);
    }

private:
    QList<T> _data;
    int _index;
};

template <const char*>
struct A{};


using namespace std;
using namespace util;
using namespace menu;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str = uint64_t2string(129197106131337, 36);
    cout << "util test string: " << str << "\n";

    QString qstr = uint64_t2qstring(129197106131337, 36);
    qDebug() << "util test qstring:" << qstr;

    QString qstr1 = uint64_t2qstring_ext(14593521163454661818U);
    qDebug() << "util test qstring (base62):" << qstr1;


    util::CuteCreator<QObject, Hi::TestA> cra;
    util::CuteCreator<QObject, Hi::TestB> crb;
    util::CuteCreator<QObject, Hi::TestC> crc;
    {
        auto obj = util::CuteFactory<QObject>::create("Hi::TestA");
        qDebug() << "Object:" << obj;

        qDebug() << "Class name:" << obj->metaObject()->className();
    }

    {
        auto obj = util::CuteFactory<QObject>::create("Hi::TestB");
        qDebug() << "Object:" << obj;

        qDebug() << "Class name:" << obj->metaObject()->className();
    }

    {
        auto obj = util::CuteFactory<QObject>::create("Hi::TestC");
        qDebug() << "Object:" << obj;

        qDebug() << "Class name:" << obj->metaObject()->className();
    }

    qDebug() << "--------------------------------------------------------------";
    {
        REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestA);
        REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestB);
        REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestC);

        {
            auto obj = Factory<QObject>::create("Hi::TestA");
            qDebug() << "Object:" << obj;
            qDebug() << "Class name:" << obj->metaObject()->className();
        }
        {
            auto obj = Factory<QObject>::create("Hi::TestB");
            qDebug() << "Object:" << obj;
            qDebug() << "Class name:" << obj->metaObject()->className();
        }
        {
            auto obj = Factory<QObject>::create("Hi::TestC");
            qDebug() << "Object:" << obj;
            qDebug() << "Class name:" << obj->metaObject()->className();
        }

        Factory<QObject>::clear();
    }

    qDebug() << "--------------------------------------------------------------";
    {
       LineCommandTranslator trans;
       CommandInfo ci = trans.translate("add 12 13 14 15");
       qDebug() << ci.name() << ci.args();
    }

    qDebug() << "--------------------------------------------------------------";
    TestT<QString, 1> tt;
    tt.setData({"first","second","third"});

    qDebug() << "TT VALUE:" << tt.value();

    qDebug() << "--------------------------------------------------------------";
    Console console;
    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));
    qDebug() << "--------------------------------------------------------------";

    {
        LazyPointer<uniq::Value<QString>> lp("uniq::TimeQStringValue");
        qDebug() << "LAZY UNIQUE VALUE:" << lp.ptr()->value();
    }
    {
        LazyPointer<uniq::Value<QString>> lp("uniq::UuidValue");
        qDebug() << "LAZY UNIQUE VALUE:" << lp.ptr()->value();
    }
    {
        LazyPointer<uniq::Value<QString>> lp("uniq::CompactUuidValue");
        qDebug() << "LAZY UNIQUE VALUE:" << lp.ptr()->value();
    }

    return a.exec();
}
