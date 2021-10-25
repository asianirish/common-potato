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

    bool containsId(const QString &id) final;

    ItemPtr child(const QString &id) const final;

    void addChild(ItemPtr item) final;

    IdList idList() const final;

private:
    C _children;
};

typedef NodeImpl<QMap<Id, ItemPtr> > NodeMapImpl;
typedef NodeImpl<QHash<Id, ItemPtr> > NodeHashImpl;

template<typename C>
bool NodeImpl<C>::containsId(const QString &id)
{
    return _children.contains(id);
}

template<typename C>
ItemPtr NodeImpl<C>::child(const QString &id) const
{
    return _children.value(id);
}

template<typename C>
void NodeImpl<C>::addChild(ItemPtr item)
{
    _children.insert(item->id(), item);
    item->setParentNode(this);
}

template<typename C>
IdList NodeImpl<C>::idList() const
{
    return _children.keys();
}

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
