#include "ImplCreator.h"
#include "Node.h"

namespace hierhin {

ImplCreator::ImplCreator()
{

}

ItemPtr ImplCreator::createItem(const BaseType &baseType)
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
