
#include "HierhinClassRegistry.h"
#include "Menu/TestItem.h"
#include "Menu/ItemVal.h"

#include <menu/Console.h>
#include <util/gfunc.h>

#include <QCoreApplication>
#include <QDebug>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    translator.load("hierhin_pl");
    a.installTranslator(&translator);

    QTranslator translator1;
    translator1.load("vallib_pl");
    a.installTranslator(&translator1);

    QString hi(QObject::tr("hi"));
    qDebug() << hi;
    double n;

    {
        n = 0;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 1;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 3.14;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 50;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }

    {
        n = 3.14;
        QString object(QObject::tr("pi is %1 of conventional units").arg(n));
        qDebug() << object;
    }

    QByteArray testEmailMsg("wrong email format");

    qDebug() << "1. email error msg:" << QObject::tr(testEmailMsg.data());
    qDebug() << "2. email error msg:" << QObject::tr("wrong email format");
    qDebug() << "3. email error msg:" << QByteArray("wrong email format");

    qDebug() << "3,14 is number: " << util::isNumber(3.14);
    qDebug() << "3,14 is integer: " << util::isInteger(3.14);

    qDebug() << "3,0 is number: " << util::isNumber(3.);
    qDebug() << "3,0 is integer: " << util::isInteger(3.);

    float fpi = 3.14;
    qDebug() << "float is number: " << util::isNumber(fpi);
    qDebug() << "float is integer: " << util::isInteger(fpi);

    double dpi = 3.14;
    qDebug() << "double is number: " << util::isNumber(dpi);
    qDebug() << "double is integer: " << util::isInteger(dpi);

    int num = 100;
    qDebug() << "int is number: " << util::isNumber(num);
    qDebug() << "int is integer: " << util::isInteger(num);


    menu::Console console(new HierhinClassRegistry());

    //TODO: add items here
    console.addMenuItem("testi", menu::ActionPtr(new TestItem()));
    console.addMenuItem("testval", menu::ActionPtr(new ItemVal()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}
