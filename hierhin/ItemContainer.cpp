#include "ItemContainer.h"

namespace hierhin {

ItemContainer::ItemContainer()
{

}

Id ItemContainer::indexToKeyType(int index, const ItemPtr &item)
{
    (void)index;
    return item->id();
}

} // namespace hierhin
