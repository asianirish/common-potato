#include "HierhinClassRegistry.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"
#include "Test/TestEssenceC.h"

#include "stock_v0/Exchange.h"

#include <hierhin/nav/ItemRef.h>

#include <util/Factory.h>

#include <menu/math/Div.h>
#include <menu/math/Inc.h>


#include <QString>


HierhinClassRegistry::HierhinClassRegistry()
{

}

void HierhinClassRegistry::registerAllClasses() const
{
    qRegisterMetaType<TestType>();

    qRegisterMetaType<hierhin::nav::ItemRef>();
    QMetaType::registerConverter<hierhin::nav::ItemRef, QString>(&hierhin::nav::ItemRef::toString);
    QMetaType::registerConverter<QString, hierhin::nav::ItemRef>(hierhin::nav::stringToItemRef);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceA);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceB);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceC);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, stock_v0::Exchange);

    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, menu::math::Div);
    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, menu::math::Inc);

    //TODO: add your code here
}
