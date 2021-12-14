#include "ItemCreator.h"
#include "Node.h"

namespace hierhin {

ItemCreator::ItemCreator()
{

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
