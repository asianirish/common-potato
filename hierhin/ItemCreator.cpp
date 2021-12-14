#include "ItemCreator.h"
#include "Node.h"

namespace hierhin {

ItemCreator::ItemCreator()
{

}

ItemPtr ItemCreator::createItem(const QVariantMap &mp)
{
    BaseType bt = static_cast<BaseType>(mp.value(Item::BASE_TYPE_KEY).toInt());
    auto item = createItem(bt);
    item->fromMap(mp);
    return item;
}

ItemPtr ItemCreator::createItem(const BaseType &baseType)
{
    switch (baseType) {
    case BaseType::ITEM:
        return createItem();
    case BaseType::NODE:
        return createNode();
    case BaseType::LINK:
        /*return createLink()*/;
    }

    return {}; //TODO: exception
}

} // namespace hierhin
