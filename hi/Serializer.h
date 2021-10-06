#ifndef HI_SERIALIZER_H
#define HI_SERIALIZER_H

#include "Item.h"

namespace hi {

class Serializer
{
public:
    Serializer();

    QByteArray serialize(const ItemPtr &item) const;
    ItemPtr deserializeToItem(const QByteArray &data) const;

private:
    virtual QByteArray serialize(const QVariantMap &mp) const = 0;
    virtual QVariantMap deserializeToMap(const QByteArray &data) const = 0;
};

/*
TODO:
JsonSerializer
XmlSerializer
BinSerializer
*/

} // namespace hi

#endif // HI_SERIALIZER_H
