#include "HierhinDestructor.h"

#include <util/SingletonRegistry.h>
#include <util/ObjectRegistry.h>
#include <hierhin/Essence.h>

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
    delete _menu;
    delete _launcher;

//    potato_util::LazyRegistry<int, menu::SyncLauncher>::destruct();
    potato_util::SingletonRegistry<hierhin::Essence>::destruct();
    potato_util::ObjectRegistry<int, menu::Launcher>::destruct();
}
