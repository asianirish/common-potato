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

public:
    ItemPtr child(const QString &id) const final;

    void addChild(ItemPtr item) final;

private:
    C _childrent;
};

typedef NodeImpl<QMap<Id, ItemPtr> > NodeMapImpl;
typedef NodeImpl<QHash<Id, ItemPtr> > NodeHashImpl;

template<typename C>
ItemPtr NodeImpl<C>::child(const QString &id) const
{
    return _childrent.value(id);
}

template<typename C>
void NodeImpl<C>::addChild(ItemPtr item)
{
    _childrent.insert(item->id(), item);
    item->setParentNode(this);
}

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
