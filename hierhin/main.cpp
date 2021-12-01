
#include "HierhinClassRegistry.h"
#include "Menu/NodeTest.h"
#include "Menu/ValidatorTest.h"
#include "Menu/TransTest.h"

#include <menu/Console.h>
#include <menu/util/SetLanguage.h>

#include <util/gfunc.h>

#include <QCoreApplication>
#include <QDebug>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    translator.load("hierhin_en");
    QCoreApplication::installTranslator(&translator);

    QTranslator translator1;
    translator1.load("vallib_en");
    QCoreApplication::installTranslator(&translator1);

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
    console.addMenuItem("testnode", menu::ActionPtr(new NodeTest()));
    console.addMenuItem("testval", menu::ActionPtr(new ValidatorTest()));

    menu::util::SetLanguage *setLanItem = new menu::util::SetLanguage();
    setLanItem->setFiles(QStringList{"hierhin", "vallib"});
    console.addMenuItem("setlan", menu::ActionPtr(setLanItem));

    console.addMenuItem("testtr", menu::ActionPtr(new TransTest()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}
