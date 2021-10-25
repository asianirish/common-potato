#ifndef DIRECT_NODEIMPL_H
#define DIRECT_NODEIMPL_H

#include "Node.h"
#include "ItemImpl.h"

#include <QMap>
#include <QHash>

namespace hierhin {
namespace direct {

template <typename C>
class NodeImpl : public virtual Node, public ItemImpl
{

private:
    C _childrent;
};

typedef NodeImpl<QMap<Id, ItemPtr> > NodeMapImpl;
typedef NodeImpl<QHash<Id, ItemPtr> > NodeHashImpl;

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
