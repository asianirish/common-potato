#include "ItemContextSetter.h"
#include "Item.h"
#include "Method.h"

namespace hierhin {

ItemContextSetter::ItemContextSetter() : _item(nullptr)
{

}

void ItemContextSetter::setActionContext(menu::Action *action)
{
    Method *iAction = dynamic_cast<Method *>(action);
    if (iAction) {
        iAction->setItem(_item);
    }
}

Item *ItemContextSetter::item() const
{
    return _item;
}

void ItemContextSetter::setItem(Item *newItem)
{
    _item = newItem;
}

} // namespace hierhin
