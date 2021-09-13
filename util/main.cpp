#include "gfunc.h"
#include "Test/TestA.h"
#include "Test/TestB.h"
#include "Test/TestC.h"

#include <util/CuteFactory.h>

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


    util::CuteCreator<QObject, Hi::TestA>();
    util::CuteCreator<QObject, Hi::TestB>();
    util::CuteCreator<QObject, Hi::TestC>();

    auto obj = util::CuteFactory<QObject>::create("Hi::TestA");
    qDebug() << "Object:" << obj;

    qDebug() << "Class name:" << obj->metaObject()->className();

    return a.exec();
}
