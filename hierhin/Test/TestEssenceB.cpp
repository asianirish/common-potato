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
    propDefValue.setName("value");

    PropertyDef propDefPi;
    propDefPi.setName("pi");

    nd.insertPropertyDef(propDefValue);
    nd.insertPropertyDef(propDefPi);

    return nd;
}
