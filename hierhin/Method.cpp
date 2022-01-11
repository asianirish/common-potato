#include "Method.h"

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

QVariant Method::simplyAct(const QVariantList &args)
{
    return actImpl(args, _item);
}

} // namespace hierhin
