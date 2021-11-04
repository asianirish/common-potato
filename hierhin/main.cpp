
#include "HierhinClassRegistry.h"
#include "Menu/TestItem.h"

#include <menu/Console.h>

#include <QCoreApplication>
#include <QDebug>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    translator.load("hierhin_en");

    a.installTranslator(&translator);

    QString hi(QObject::tr("hi"));
    qDebug() << hi;
    int n;

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
        n = 3;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }
    {
        n = 50;
        QString object(QObject::tr("%n object(s)", "", n));
        qDebug() << object;
    }


    menu::Console console(new HierhinClassRegistry());

    //TODO: add items here
    console.addMenuItem("testi", menu::ActionPtr(new TestItem()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}
