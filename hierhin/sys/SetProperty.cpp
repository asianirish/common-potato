#include "SetProperty.h"

namespace hierhin {
namespace sys {

SetProperty::SetProperty()
{

}

menu::def::ActionDef SetProperty::actionDef() const
{
    menu::def::ActionDef aDef;
    menu::def::ArgDef keyDef;
    menu::def::ArgDef valueDef;

    aDef.setArgMinNum(2);

    aDef.addArgDef(keyDef);
    aDef.addArgDef(valueDef);

    return aDef;
}

QVariant SetProperty::actImpl(const QVariantList &args, Item *item)
{
    QString propName = args.at(0).toString();
    QVariant value = args.at(1);

    item->setProperty(propName, value);

    return true;
}

} // namespace sys
} // namespace hierhin
