#include "Method.h"
#include "ex/NoItem.h"

namespace hierhin {

Method::Method() : _item(nullptr)
{

}

Item *Method::item() const
{
    return _item;
}

void Method::setItem(Item *item)
{
    _item = item;
}

QVariant Method::simplyAct(const QVariantList &args, const menu::TaskId &taskId)
{
    if (!_item) {
        throw ex::NoItem();
    }

    return actImpl(args, _item, taskId);
}

} // namespace hierhin
