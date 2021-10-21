
#include "HierhinClassRegistry.h"

#include <menu/Console.h>
#include <hierhin/Abstract/Item.h>

#include <QCoreApplication>
#include <QDebug>

using namespace hierhin;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hierhin";
    menu::Console console(new HierhinClassRegistry());

    Item item;

    qDebug() << "ID:" << item.id();



    //TODO: add items here


    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}
