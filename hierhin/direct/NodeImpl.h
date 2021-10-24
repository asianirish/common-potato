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

typedef NodeImpl<QMap<Id, ItemPtr> > NodeMapImpl;
typedef NodeImpl<QHash<Id, ItemPtr> > NodeHashImpl;

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
