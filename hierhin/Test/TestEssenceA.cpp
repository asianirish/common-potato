#include "TestEssenceA.h"

#include <hierhin/Item.h>
#include <val/LessThanOrEqualTo.h>
#include <val/MoreThanOrEqualTo.h>
#include <val/Range.h>
#include <val/Email.h>

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

    {
        PropertyDef propDefValue;
        ValidatorPtr ltoet = ValidatorPtr(new val::Range<int>(13, 1337 * 2));
        propDefValue.addValidator(ltoet);
        nd.insertPropertyDef("value", propDefValue);
    }

    {
        PropertyDef propDefValue;
        propDefValue.addValidator(ValidatorPtr(new val::Email()));
        nd.insertPropertyDef("email", propDefValue);
    }


    return nd;
}
