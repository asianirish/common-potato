
#include "HierhinClassRegistry.h"
#include "Menu/NodeTest.h"
#include "Menu/ValidatorTest.h"
#include "Menu/TransTest.h"
#include "Menu/NumberTest.h"

#include <menu/Console.h>
#include <menu/util/SetLanguage.h>

#include <QCoreApplication>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    menu::Console console(new HierhinClassRegistry());

    //TODO: add items here
    console.addMenuItem("testnode", menu::ActionPtr(new NodeTest()));
    console.addMenuItem("testval", menu::ActionPtr(new ValidatorTest()));

    menu::util::SetLanguage *setLanItem = new menu::util::SetLanguage();
    setLanItem->setFiles(QStringList{"hierhin", "vallib"});
    console.addMenuItem("setlan", menu::ActionPtr(setLanItem));

    console.addMenuItem("testtr", menu::ActionPtr(new TransTest()));
    console.addMenuItem("testnum", menu::ActionPtr(new NumberTest()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
