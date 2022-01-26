#include "ItemCreatorImpl.h"
#include "NodeImpl.h"

namespace hierhin {
namespace cute {

ItemCreatorImpl::ItemCreatorImpl()
{

}

ItemPtr ItemCreatorImpl::createItem() const
{
    return ItemPtr(new ItemImpl());
}

NodePtr ItemCreatorImpl::createNode() const
{
    return NodePtr(new NodeImpl());
}

} // namespace cute
} // namespace hierhin
