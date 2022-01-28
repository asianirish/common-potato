#include "ItemImpl.h"
#include "Node.h"
#include "ItemCreatorImpl.h"

namespace hierhin {
namespace cute {

ItemImpl::ItemImpl()
{

}

NodeWeakPtr ItemImpl::parentNode() const
{
    return _parentNode;
}

void ItemImpl::setParentNodeImpl(NodeWeakPtr parentNode)
{
    _parentNode = parentNode;
}

ItemCreator *ItemImpl::createCreator() const
{
    return new ItemCreatorImpl();
}

} // namespace cute
} // namespace hierhin
