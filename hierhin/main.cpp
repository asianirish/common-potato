
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

    //TODO: add items here
    console.addMenuItem("tnode", menu::ActionPtr(new NodeTest()));
    console.addMenuItem("tval", menu::ActionPtr(new ValidatorTest()));

    menu::util::SetLanguage *setLanItem = new menu::util::SetLanguage();
    setLanItem->setFiles(QStringList{"hierhin", "vallib", "menulib"});
    console.addMenuItem("setlan", menu::ActionPtr(setLanItem));

    console.addMenuItem("ttr", menu::ActionPtr(new TransTest()));
    console.addMenuItem("tnum", menu::ActionPtr(new NumberTest()));
    console.addMenuItem("tclone", menu::ActionPtr(new CloneTest()));
    console.addMenuItem("tlink", menu::ActionPtr(new LinkTest()));
    console.addMenuItem("tcmd", menu::ActionPtr(new CommandTest()));
    console.addMenuItem("tlaunch", menu::ActionPtr(new LauncherTest()));

    {
        console.addMenuItem("tnode", "NodeTest");
        console.addMenuItem("tval", "ValidatorTest");

        console.addMenuItem("setlan", "menu::util::SetLanguage");

        console.addMenuItem("ttr", "TransTest");
        console.addMenuItem("tnum", "NumberTest");
        console.addMenuItem("tclone", "CloneTest");
        console.addMenuItem("tlink", "LinkTest");
        console.addMenuItem("tcmd", "CommandTest");
        console.addMenuItem("tlaunch", "LauncherTest");
    }

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
