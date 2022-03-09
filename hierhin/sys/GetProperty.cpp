#include "GetProperty.h"

namespace hierhin {
namespace sys {

GetProperty::GetProperty()
{

}

menu::def::ActionDef GetProperty::actionDef() const
{
    menu::def::ActionDef aDef;
    menu::def::ArgDef argDef;
    aDef.setArgMinNum(1);
    aDef.setArgMaxNum(1);
    aDef.addArgDef(argDef);
    //TODO: aDef.set...
    return aDef;
}

QVariant GetProperty::actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId)
{
    QString propName = args.at(0).toString();
    return item->property(propName);
}

} // namespace sys
} // namespace hierhin
