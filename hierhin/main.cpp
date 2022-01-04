
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
    menu::Launcher *launcher = new menu::ThreadLauncher();
    menu->setLauncher(launcher);

    new HierhinDestructor(&a, menu, launcher);

    menu::Console console(new HierhinClassRegistry(), menu);

    {
        console.addMenuItem("tnode", "NodeTest");

        console.addMenuItem("tval", "ValidatorTest");

        console.addMenuItem("setlan", "menu::util::SetLanguage");

        console.addMenuItem("ttr", "TransTest");
        console.addMenuItem("tnum", "NumberTest");

//        console.addMenuItem("tclone", "CloneTest");
        ADD_MENU_ITEM(console, tclone, CloneTest)

        console.addMenuItem("tlink", "LinkTest");

//        console.addMenuItem("tcmd", "CommandTest");
        ADD_MENU_ITEM(console, tcmd, CommandTest)

        console.addMenuItem("tlaunch", "LauncherTest");
    }

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
