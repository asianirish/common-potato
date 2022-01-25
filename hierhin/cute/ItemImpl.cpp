#include "ItemImpl.h"
#include "Node.h"
//TODO: #include "ItemCreatorImpl.h"

namespace hierhin {
namespace cute {

ItemImpl::ItemImpl()
{

}

NodeWeakPtr ItemImpl::parentNode() const
{
    return _parentNode;
}

void ItemImpl::setParentNode(NodeWeakPtr parentNode)
{
    if (parentNode && parentNode.lock()->containsId(this->id())) {
        _parentNode = parentNode;
    }
}

ItemCreator *ItemImpl::createCreator() const
{
//TODO:    return new ItemCreatorImpl();
    //TODO: implement
    return nullptr; //TODO: delete this line
}

} // namespace cute
} // namespace hierhin
