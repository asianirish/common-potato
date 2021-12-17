#include "HierhinClassRegistry.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"
#include "Test/TestEssenceC.h"

#include "stock_v0/Exchange.h"

#include <hierhin/nav/ItemRef.h>

#include <util/Factory.h>

#include <QString>

//QString itemRefToString(const hierhin::nav::ItemRef itemRef) {
//    return itemRef.operator QString();
//}

hierhin::nav::ItemRef stringToItemRef(const QString str) {
    return hierhin::nav::ItemRef(str);
}

HierhinClassRegistry::HierhinClassRegistry()
{

}

void HierhinClassRegistry::registerAllClasses() const
{
    qRegisterMetaType<TestType>();

    qRegisterMetaType<hierhin::nav::ItemRef>();
    QMetaType::registerConverter<hierhin::nav::ItemRef, QString>(&hierhin::nav::ItemRef::toString);
    QMetaType::registerConverter<QString, hierhin::nav::ItemRef>(stringToItemRef);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceA);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceB);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceC);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, stock_v0::Exchange);

    //TODO: add your code here
}
