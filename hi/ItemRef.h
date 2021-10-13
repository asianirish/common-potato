#ifndef HI_ITEMREF_H
#define HI_ITEMREF_H

#include <QString>

namespace hi {

class Item;

class ItemRef
{
public:
    ItemRef();

    ItemRef(const QString &id, Item *item = nullptr);

    QString id() const;
    void setId(const QString &id);

    Item *item() const;
    void setItem(Item *item);

private:
    QString _id;
    Item *_item;
};

} // namespace hi

#endif // HI_ITEMREF_H
