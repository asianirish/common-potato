#include "TestEssenceB.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceB::TestEssenceB()
{

}

NodeDef TestEssenceB::nodeDef() const
{
    NodeDef nd;

    PropertyDef propDefValue;
    PropertyDef propDefPi;

    nd.insertPropertyDef("value", propDefValue);
    nd.insertPropertyDef("pi", propDefPi);

    return nd;
}

void TestEssenceB::executeImpl(hierhin::Item *item) const
{
    item->setProperty("pi", 3.1415926535);
}
