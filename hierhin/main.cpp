
#include "HierhinClassRegistry.h"
#include "HierhinDestructor.h"
#include "HierhinContextSetter.h"

#include "Menu/NodeTest.h"
#include "Menu/ValidatorTest.h"
#include "Menu/TransTest.h"
#include "Menu/NumberTest.h"
#include "Menu/CloneTest.h"
#include "Menu/RefTest.h"
#include "Menu/CommandTest.h"
#include "Menu/LauncherTest.h"
#include "Menu/LazyRegistryTest.h"
#include "Menu/MethodTest.h"
#include <Menu/RegTest.h>
#include <Menu/ConvTest.h>

#include <menu/Console.h>
#include <menu/util/SetLanguage.h>
#include <menu/SyncLauncher.h>

#include <hierhin/ItemContextSetter.h>

#include <QCoreApplication>

#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    menu::Menu *menu = new menu::Menu();
    HierhinContextSetter *cntx = new HierhinContextSetter();
    menu->setContextSetter(cntx);

//    menu::Launcher *launcher = new menu::ThreadLauncher();
    menu::Launcher *launcher = new menu::SyncLauncher();
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

    ADD_MENU_ITEM(console, tref, RefTest)

    ADD_MENU_ITEM(console, tlaunch, LauncherTest)

    ADD_MENU_ITEM(console, tlazy, LazyRegistryTest)

    ADD_MENU_ITEM(console, tmethod, MethodTest)

    ADD_MENU_ITEM(console, treg, RegTest)

    ADD_MENU_ITEM(console, tconv, ConvTest)

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
