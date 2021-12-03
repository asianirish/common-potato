#include "TestEssenceA.h"

#include <hierhin/Item.h>

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
    nd.insertPropertyDef("value", propDefValue);

    return nd;
}
