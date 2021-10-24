#ifndef DIRECT_NODEIMPL_H
#define DIRECT_NODEIMPL_H

#include "Node.h"

namespace hierhin {
namespace direct {

template <typename C>
class NodeImpl : public Node
{

private:
    C _childrent;
};

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
