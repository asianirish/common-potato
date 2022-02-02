#include "ItemCreator.h"
#include "Node.h"

#include "ex/NoSuchBaseType.h"

namespace hierhin {

ItemCreator::ItemCreator()
{

}

ItemPtr ItemCreator::createItem(const QVariantMap &mp) const
{
    BaseType bt = static_cast<BaseType>(mp.value(Item::BASE_TYPE_KEY).toInt());
    auto item = createItem(bt);
    item->fromMap(mp);
    return item;
}

ItemPtr ItemCreator::createItem(const BaseType &baseType) const
{
    switch (baseType) {
    case BaseType::ITEM:
        return createItem();
    case BaseType::NODE:
        return createNode();
    }

    throw ex::NoSuchBaseType(static_cast<int>(baseType));
}

} // namespace hierhin
