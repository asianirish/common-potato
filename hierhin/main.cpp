
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
#include <Menu/SayHiContextSetter.h>

#include <util/FriendlyByteArray.h>

#include <menu/Console.h>
#include <menu/util/SetLanguage.h>
#include <menu/SyncLauncher.h>

#include <menu/Error.h>

#include <hierhin/ItemContextSetter.h>

#include <QCoreApplication>

#include <QTranslator>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray ba("TURAMBARBARMATOR");

    qDebug() << "MID" << ba.mid(4,3);
    FriendlyByteArray fba(ba, true);
    fba.setMessage("OLIMEX");

    qDebug() << "1. FBA" << fba.data();

    fba = fba.mid(3,4);

    qDebug() << "2. FBA" << fba.data();

    try {
        qDebug() << fba.at(44);
    } catch (const QString &msg) {
        qDebug() << "ERROR:" << msg;
    }



//TEST ENUM:
    QString s = QVariant::fromValue(menu::Error::NO_MENU_ERROR).toString();
    cout << "ENUM AS STRING: " << s.toStdString() << endl;

    menu::Menu *menu = new menu::Menu();

    menu::Launcher *launcher = new menu::ThreadLauncher();
//    menu::Launcher *launcher = new menu::SyncLauncher();
    menu->setLauncher(launcher);

    new HierhinDestructor(&a, menu, launcher);

    auto registry = new HierhinClassRegistry();
    menu::Console console(registry, menu);
    delete registry;

    REGISTER_COMMAND(console, tnode, NodeTest);

    REGISTER_COMMAND(console, tval, ValidatorTest);

    {
        auto cntxPtr = menu::ContextSetterPtr(new HierhinContextSetter());
        REGISTER_COMMAND_X(console, setlan, menu::util::SetLanguage, cntxPtr);
    }

    REGISTER_COMMAND(console, ttr, TransTest);

    REGISTER_COMMAND(console, tnum, NumberTest);

    REGISTER_COMMAND(console, tclone, CloneTest);

    REGISTER_COMMAND(console, tref, RefTest);

    REGISTER_COMMAND(console, tlaunch, LauncherTest);

    REGISTER_COMMAND(console, tlazy, LazyRegistryTest);

    REGISTER_COMMAND(console, tmethod, MethodTest);

    REGISTER_COMMAND(console, treg, RegTest);

    REGISTER_COMMAND(console, tconv, ConvTest);

    REGISTER_COMMAND(console, tch, ChildTest);

    REGISTER_COMMAND(console, thmlink, HandMadeLinkTest);

    REGISTER_COMMAND(console, tlink, LinkTest);

    REGISTER_COMMAND(console, tmlt, MultyPropertyTest);

    REGISTER_COMMAND(console, tcc, CuteContainerTest);

    REGISTER_COMMAND(console, tbimap, BiMapTest);

    REGISTER_COMMAND(console, tesscl, EssenceClassTest);

    {
        auto cntxPtr = menu::ContextSetterPtr(new SayHiContextSetter());
        REGISTER_COMMAND_X(console, sayhi, SayHi, cntxPtr);
    }
    {
        auto cntxPtr = menu::ContextSetterPtr(new SayHiContextSetter(SayHi::HELLO));
        REGISTER_COMMAND_X(console, sayhello, SayHi, cntxPtr);
    }
    {
        auto cntxPtr = menu::ContextSetterPtr(new SayHiContextSetter(SayHi::GOOD_DAY));
        REGISTER_COMMAND_X(console, saygoodday, SayHi, cntxPtr);
    }

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
