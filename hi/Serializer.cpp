#include "Serializer.h"

namespace hi {

Serializer::Serializer()
{

}

QByteArray Serializer::serialize(const ItemPtr &item) const
{
    return serialize(item->toMap());
}

ItemPtr Serializer::deserializeToItem(const QByteArray &data) const
{
    QVariantMap mp = deserializeToMap(data);
    return Item::newItem(mp);
}

} // namespace hi
