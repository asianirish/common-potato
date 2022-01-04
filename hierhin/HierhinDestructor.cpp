#include "HierhinDestructor.h"

#include <menu/ContextSetter.h>

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
    menu::ContextSetter *cntx = _launcher->contextSetter();
    delete cntx;
    delete _menu;
    delete _launcher;
}
