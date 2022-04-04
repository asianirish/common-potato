#include "DRandProperty.h"

#include <util/gfunc.h>

namespace hierhin {
namespace sys {

DRandProperty::DRandProperty()
{

}

menu::def::ActionDef DRandProperty::actionDef() const
{
    menu::def::ActionDef aDef;
    aDef.setArgMinNum(3); //3 taking into account the default values

    menu::def::ArgDef keyDef;
    keyDef.setName("key");

    menu::def::ArgDef minDef;
    minDef.setName("min");
    minDef.setTypeId(QMetaType::Double);
    minDef.setDefaultValue(0.);

    menu::def::ArgDef maxDef;
    maxDef.setName("max");
    maxDef.setTypeId(QMetaType::Double);
    maxDef.setDefaultValue(1.);

    aDef.addArgDef(keyDef);
    aDef.addArgDef(minDef);
    aDef.addArgDef(maxDef);

    return aDef;
}

QVariant DRandProperty::actImpl(const QVariantList &args, Item *item)
{
    QString propName = args.at(0).toString();
    double min = args.at(1).toDouble();
    double max = args.at(2).toDouble();
    double value = dRand(min, max);

    item->setProperty(propName, value);

    return true;
}

} // namespace sys
} // namespace hierhin
