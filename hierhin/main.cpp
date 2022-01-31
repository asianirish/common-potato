
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
#include <Menu/ChildTest.h>
#include <Menu/HandMadeLinkTest.h>
#include <Menu/LinkTest.h>
#include <Menu/MultyPropertyTest.h>
#include <Menu/CuteContainerTest.h>
#include <Menu/BiMapTest.h>
#include <Menu/EssenceClassTest.h>

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

    ADD_MENU_ITEM(console, tch, ChildTest)

    ADD_MENU_ITEM(console, thmlink, HandMadeLinkTest)

    ADD_MENU_ITEM(console, tlink, LinkTest)

    ADD_MENU_ITEM(console, tmlt, MultyPropertyTest)

    ADD_MENU_ITEM(console, tcc, CuteContainerTest)

    ADD_MENU_ITEM(console, tbimap, BiMapTest)

    ADD_MENU_ITEM(console, tesscl, EssenceClassTest)

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
