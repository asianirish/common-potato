#include "HierhinClassRegistry.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"
#include "Test/TestEssenceC.h"
#include "Test/PlusValue.h"

#include <hierhin/nav/ItemRef.h>
#include <hierhin/ItemAction.h>

#include <util/Factory.h>

#include <menu/math/Div.h>
#include <menu/math/Inc.h>

#include <menu/SyncLauncher.h>
#include <menu/ThreadLauncher.h>

#include <util/ObjectRegistry.h>


#include <QString>

#include <QDebug>

using namespace menu;

HierhinClassRegistry::HierhinClassRegistry()
{

}

void HierhinClassRegistry::registerAllClasses() const
{
    qRegisterMetaType<TestType>();

    qRegisterMetaType<hierhin::nav::ItemRef>();
    QMetaType::registerConverter<hierhin::nav::ItemRef, QString>(&hierhin::nav::ItemRef::toString);
    QMetaType::registerConverter<QString, hierhin::nav::ItemRef>(hierhin::nav::stringToItemRef);

    potato_util::ObjectRegistry<int, Launcher>::createObject<SyncLauncher>(0);
    potato_util::ObjectRegistry<int, Launcher>::createObject<ThreadLauncher>(1);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceA);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceB);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceC);

    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, menu::math::Div);
    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, menu::math::Inc);

    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, PlusValue);

    //TODO: add your code here
}
