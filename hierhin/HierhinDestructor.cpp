#include "HierhinDestructor.h"

#include <menu/ContextSetter.h>
#include <util/LazyRegistry.h>

#include <QDebug>

HierhinDestructor::HierhinDestructor(QCoreApplication *app, menu::Menu *menu, menu::Launcher *launcher) : AppDestructor(app),
    _menu(menu),
    _launcher(launcher)
{

}

HierhinDestructor::~HierhinDestructor()
{
   qDebug() << "HIERHIN_DUSTRUCTOR DESTRUCTOR";
}

void HierhinDestructor::cleanUp()
{
    qDebug() << "CLEANING UP...";
    menu::ContextSetter *cntx = _menu->contextSetter();
    delete cntx;
    delete _menu;
    delete _launcher;

//    potato_util::LazyRegistry<int, menu::SyncLauncher>::destruct();
}
