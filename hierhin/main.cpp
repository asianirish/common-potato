
#include "HierhinClassRegistry.h"
#include "Menu/TestItem.h"

#include <menu/Console.h>

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hierhin";
    menu::Console console(new HierhinClassRegistry());

    //TODO: add items here
    console.addMenuItem("testitem", menu::ActionPtr(new TestItem()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}
