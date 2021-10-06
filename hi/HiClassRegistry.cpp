#include "HiClassRegistry.h"

#include "test/Currency.h"

HiClassRegistry::HiClassRegistry()
{

}

void HiClassRegistry::registerAllClasses() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(hi::Item, test::Currency);
}
