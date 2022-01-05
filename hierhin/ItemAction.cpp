#include "ItemAction.h"

namespace hierhin {

ItemAction::ItemAction() : _item(nullptr)
{

}

Item *ItemAction::item() const
{
    return _item;
}

void ItemAction::setItem(Item *item)
{
    _item = item;
}

QVariant ItemAction::simplyAct(const QVariantList &args)
{
    return actImpl(args, _item);
}

} // namespace hierhin
