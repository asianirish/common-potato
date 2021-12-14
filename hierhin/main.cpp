
#include "HierhinClassRegistry.h"
#include "Menu/NodeTest.h"
#include "Menu/ValidatorTest.h"
#include "Menu/TransTest.h"
#include "Menu/NumberTest.h"
#include "Menu/CloneTest.h"

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
    console.addMenuItem("tnode", menu::ActionPtr(new NodeTest()));
    console.addMenuItem("tval", menu::ActionPtr(new ValidatorTest()));

    menu::util::SetLanguage *setLanItem = new menu::util::SetLanguage();
    setLanItem->setFiles(QStringList{"hierhin", "vallib", "menulib"});
    console.addMenuItem("setlan", menu::ActionPtr(setLanItem));

    console.addMenuItem("ttr", menu::ActionPtr(new TransTest()));
    console.addMenuItem("tnum", menu::ActionPtr(new NumberTest()));
    console.addMenuItem("tclone", menu::ActionPtr(new CloneTest()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
