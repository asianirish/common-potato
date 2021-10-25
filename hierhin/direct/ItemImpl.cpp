#include "ItemImpl.h"

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
    _parentNode = parentNode;
}

} // namespace direct
} // namespace hierhin
