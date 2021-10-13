#include "ItemRef.h"

namespace hi {

ItemRef::ItemRef() : ItemRef(QString())
{

}

ItemRef::ItemRef(const QString &id, Item *item) : _id(id), _item(item)
{

}

QString ItemRef::id() const
{
    return _id;
}

void ItemRef::setId(const QString &id)
{
    _id = id;
}

Item *ItemRef::item() const
{
    return _item;
}

void ItemRef::setItem(Item *item)
{
    _item = item;
}

} // namespace hi
