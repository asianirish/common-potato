
#include "HierhinClassRegistry.h"
#include "HierhinDestructor.h"

#include "Menu/NodeTest.h"
#include "Menu/ValidatorTest.h"
#include "Menu/TransTest.h"
#include "Menu/NumberTest.h"
#include "Menu/CloneTest.h"
#include "Menu/LinkTest.h"
#include "Menu/CommandTest.h"
#include "Menu/LauncherTest.h"

#include <menu/Console.h>
#include <menu/util/SetLanguage.h>

#include <QCoreApplication>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    menu::Menu *menu = new menu::Menu();
    menu::Launcher *launcher = new menu::ThreadLauncher(); //TODO: set HierhinContextSetter
    menu->setLauncher(launcher);

    new HierhinDestructor(&a, menu, launcher);

    auto registry = new HierhinClassRegistry();
    menu::Console console(registry, menu);
    delete registry;

    ADD_MENU_ITEM(console, tnode, NodeTest)

    ADD_MENU_ITEM(console, tval, ValidatorTest)

    ADD_MENU_ITEM(console, setlan, menu::util::SetLanguage)

    ADD_MENU_ITEM(console, ttr, TransTest)

    ADD_MENU_ITEM(console, tnum, NumberTest)

    ADD_MENU_ITEM(console, tclone, CloneTest)

    ADD_MENU_ITEM(console, tlink, LinkTest)

    ADD_MENU_ITEM(console, tcmd, CommandTest)

    ADD_MENU_ITEM(console, tlaunch, LauncherTest)

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
