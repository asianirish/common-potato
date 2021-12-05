#include "HierhinClassRegistry.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"

#include "stock_v0/Exchange.h"

#include <util/Factory.h>

#include <QString>

HierhinClassRegistry::HierhinClassRegistry()
{

}

void HierhinClassRegistry::registerAllClasses() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceA);
    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, TestEssenceB);

    REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, stock_v0::Exchange);

    //TODO: add your code here
}
