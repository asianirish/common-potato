#include "TestEssenceB.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceB::TestEssenceB()
{

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
