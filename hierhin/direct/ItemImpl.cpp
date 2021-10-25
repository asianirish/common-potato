#include "ItemImpl.h"
#include "Node.h"

namespace hierhin {
namespace direct {

ItemImpl::ItemImpl() : _parentNode(nullptr)
{

}

Node *ItemImpl::parentNode() const
{
    return _parentNode;
}

void ItemImpl::setParentNode(Node *parentNode)
{
    if (parentNode && parentNode->containsId(this->id())) {
        _parentNode = parentNode;
    }
}

} // namespace direct
} // namespace hierhin
