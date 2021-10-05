#include "gfunc.h"
#include "Test/TestClassRegistry.h"
#include "Test/TestFactory.h"
#include "Test/TestLazy.h"

#include <menu/Console.h>
#include <menu/Menu.h>
//#include <menu/LineCommandTranslator.h>
//#include <menu/JsonCommandTranslator.h>

#include <menu/math/Inc.h>
#include <menu/math/Div.h>

#include <menu/test/BuildPhrase.h>

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


    qDebug() << "--------------------------------------------------------------";
    TestT<QString, 1> tt;
    tt.setData({"first","second","third"});

    qDebug() << "TT VALUE:" << tt.value();

    qDebug() << "--------------------------------------------------------------";
    Console console(new TestClassRegistry());

    console.addMenuItem("inc", menu::ActionPtr(new menu::math::Inc()));
    console.addMenuItem("div", menu::ActionPtr(new menu::math::Div()));
    console.addMenuItem("phrase", menu::ActionPtr(new menu::test::BuildPhrase()));
    console.addMenuItem("factory", menu::ActionPtr(new TestFactory()));
    console.addMenuItem("lazy", menu::ActionPtr(new TestLazy()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
