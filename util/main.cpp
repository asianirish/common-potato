#include "gfunc.h"
#include "Test/TestA.h"
#include "Test/TestB.h"
#include "Test/TestC.h"

#include "Console.h"

#include <util/CuteFactory.h>
#include <util/Factory.h>

#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include <QObject>


using namespace std;
using namespace util;

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
    Console console;
    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
