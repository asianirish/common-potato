#ifndef HIERHIN_CUTE_ITEMIMPL_H
#define HIERHIN_CUTE_ITEMIMPL_H

#include <Item.h>

namespace hierhin {
namespace cute {

class ItemImpl : public virtual hierhin::Item
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

} // namespace cute
} // namespace hierhin

#endif // HIERHIN_CUTE_ITEMIMPL_H
