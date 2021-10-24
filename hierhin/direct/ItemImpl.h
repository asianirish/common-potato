#ifndef DIRECT_ITEMIMPL_H
#define DIRECT_ITEMIMPL_H

#include "Item.h"

#include <QHash>

namespace hierhin {
namespace direct {

template <typename C>
class ItemImpl : public Item
{
public:
    NodePtr parentNode() const override;
    void setParentNode(NodePtr parentNode) override;

private:
    C _childrent;
    NodePtr _parentNode;
};

template<typename C>
NodePtr ItemImpl<C>::parentNode() const
{
    return _parentNode;
}

template<typename C>
void ItemImpl<C>::setParentNode(NodePtr parentNode)
{
    _parentNode = parentNode;
}

typedef ItemImpl<QMap<Id, ItemPtr> > ItemMapImpl;
typedef ItemImpl<QHash<Id, ItemPtr> > ItemHashImpl;

} // namespace direct
} // namespace hierhin

#endif // DIRECT_ITEMIMPL_H
