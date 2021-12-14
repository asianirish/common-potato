#ifndef DIRECT_ITEMIMPL_H
#define DIRECT_ITEMIMPL_H

#include "Node.h"
#include "ItemCreatorImpl.h"

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

    Node *parentNode() const override;
    void setParentNode(Node *parentNode) override;

    ItemCreator *createCreator() const;

private:
    Node *_parentNode;
};

template <typename C>
ItemImpl<C>::ItemImpl() : _parentNode(nullptr)
{

}

template <typename C>
Node *ItemImpl<C>::parentNode() const
{
    return _parentNode;
}

template <typename C>
void ItemImpl<C>::setParentNode(Node *parentNode)
{
    if (parentNode && parentNode->containsId(this->id())) {
        _parentNode = parentNode;
    }
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
