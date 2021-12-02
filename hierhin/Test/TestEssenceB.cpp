#include "TestEssenceB.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceB::TestEssenceB()
{

}

void TestEssenceB::execute(hierhin::Item *item)
{
    item->setProperty("pi", 3.1415926535);
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
