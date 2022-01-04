#include "HierhinDestructor.h"

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
}
