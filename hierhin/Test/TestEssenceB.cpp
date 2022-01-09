#include "TestEssenceB.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceB::TestEssenceB()
{

}

NodeDef TestEssenceB::nodeDef() const
{
    NodeDef nd;

    auto propDefs = propertyDefs();
    nd.setPropertyDefs(propDefs); //TODO: in parent class

    return nd;
}

QMap<QString, PropertyDef> TestEssenceB::propertyDefs() const
{
    QMap<QString, PropertyDef> propDefs;

    PropertyDef propDefValue;
    propDefValue.setName("value");

    PropertyDef propDefPi;
    propDefPi.setName("pi");

    propDefs.insert(propDefValue.name(), propDefValue);
    propDefs.insert(propDefPi.name(), propDefPi);

    return propDefs;
}
