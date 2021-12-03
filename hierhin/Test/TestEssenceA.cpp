#include "TestEssenceA.h"

#include <hierhin/Item.h>
#include <val/LessThanOrEqualTo.h>
#include <val/MoreThanOrEqualTo.h>

#include <QDebug>

TestEssenceA::TestEssenceA()
{

}

void TestEssenceA::execute(hierhin::Item *item)
{
    int value = item->property("value").toInt();
    item->setProperty("value", value * 2);
}

NodeDef TestEssenceA::nodeDef() const
{
    NodeDef nd;

    nd.setIsLimitedPropertyList(true);

    PropertyDef propDefValue;
    ValidatorPtr ltoet = ValidatorPtr(new val::LessThanOrEqualTo<int>(1337 * 2));
    propDefValue.addValidator(ltoet);
    ValidatorPtr mtoet = ValidatorPtr(new val::MoreThanOrEqualTo<int>(13));
    propDefValue.addValidator(mtoet);

    nd.insertPropertyDef("value", propDefValue);

    return nd;
}
