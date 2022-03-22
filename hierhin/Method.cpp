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

menu::Result Method::act(Item *item, const QVariantList &args)
{
    setItem(item);
    return Action::act(args);
}

menu::Result Method::act(Item *item, const QVariantMap &namedArgs)
{
    setItem(item);
    return Action::act(namedArgs);
}

QVariant Method::simplyAct(const QVariantList &args, const menu::TaskId &taskId)
{
    if (!_item) {
        throw ex::NoItem();
    }

    return actImpl(args, _item, taskId);
}

} // namespace hierhin
