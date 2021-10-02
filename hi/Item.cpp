#include "Item.h"

namespace hi {

Item::Item(QObject *parent) : QObject(parent)
{

}

QVariant Item::field(const QString &name) const
{
    return _fields.value(name);
}

void Item::setField(const QString &name, const QVariant &value)
{
    _fields.insert(name, value);
}

} // namespace hi
