#include "ItemImpl.h"

namespace hierhin {
namespace direct {

NodePtr ItemImpl::parentNode() const
{
    return _parentNode;
}

void ItemImpl::setParentNode(NodePtr parentNode)
{
    _parentNode = parentNode;
}

} // namespace direct
} // namespace hierhin
