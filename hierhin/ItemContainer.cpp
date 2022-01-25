#include "ItemContainer.h"

namespace hierhin {

ItemContainer::ItemContainer()
{

}

Id ItemContainer::indexToKeyType(int index)
{
    return at(index)->id();
}

} // namespace hierhin
