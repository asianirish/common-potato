#ifndef HIERHIN_DIRECT_ITEMCREATORIMPL_H
#define HIERHIN_DIRECT_ITEMCREATORIMPL_H

#include <ItemCreator.h>

namespace hierhin {
namespace direct {

template <typename C>
class NodeImpl;

template <typename C>
class ItemImpl;

template <typename C>
class ItemCreatorImpl : public ItemCreator
{
public:
    ItemCreatorImpl();

private:
    ItemPtr createItem() const final;
    NodePtr createNode() const final;
//TODO:    LinkPtr createLink() final;
};

template <typename C>
ItemCreatorImpl<C>::ItemCreatorImpl()
{

}

template <typename C>
ItemPtr ItemCreatorImpl<C>::createItem() const
{
    return ItemPtr(new ItemImpl<C>());
}

template<typename C>
NodePtr ItemCreatorImpl<C>::createNode() const
{
    return NodePtr(new NodeImpl<C>());
}

} // namespace direct
} // namespace hierhin

#endif // HIERHIN_DIRECT_ITEMCREATORIMPL_H
