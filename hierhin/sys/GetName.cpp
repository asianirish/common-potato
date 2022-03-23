#include "GetName.h"

namespace hierhin {
namespace sys {

GetName::GetName()
{

}

menu::def::ActionDef GetName::actionDef() const
{
    menu::def::ActionDef aDef;
    //TODO: aDef.set...
    return aDef;
}

QVariant GetName::actImpl(const QVariantList &args, Item *item)
{
    Q_UNUSED(args)
    return item->property("name");
}

} // namespace sys
} // namespace hierhin
