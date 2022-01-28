#ifndef DIRECT_ITEMIMPL_H
#define DIRECT_ITEMIMPL_H

#include "ItemCreatorImpl.h"
#include <Node.h>
#include <QHash>

namespace hierhin {
namespace direct {

template <typename C>
class ItemCreatorImpl;

template <typename C>
class ItemImpl : public virtual Item
{
public:
    ItemImpl();

    virtual ~ItemImpl() = default;

    NodeWeakPtr parentNode() const override;

    ItemCreator *createCreator() const override;

private:
    NodeWeakPtr _parentNode;

    void setParentNodeImpl(NodeWeakPtr parentNode) override;
};

template <typename C>
ItemImpl<C>::ItemImpl() /*: _parentNode(nullptr)*/
{

}

template <typename C>
NodeWeakPtr ItemImpl<C>::parentNode() const
{
    return _parentNode;
}

template <typename C>
void ItemImpl<C>::setParentNodeImpl(NodeWeakPtr parentNode)
{
    _parentNode = parentNode;
}

template<typename C>
ItemCreator *ItemImpl<C>::createCreator() const
{
    return new ItemCreatorImpl<C>();
}


typedef ItemImpl<QMap<Id, ItemPtr> > ItemMapImpl;
typedef ItemImpl<QHash<Id, ItemPtr> > ItemHashImpl;

} // namespace direct
} // namespace hierhin

#endif // DIRECT_ITEMIMPL_H
