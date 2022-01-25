#ifndef HIERHIN_CUTE_ITEMIMPL_H
#define HIERHIN_CUTE_ITEMIMPL_H

#include <Item.h>

namespace hierhin {
namespace cute {

class ItemImpl : public hierhin::Item
{
public:
    ItemImpl();

    virtual ~ItemImpl() = default;

    NodeWeakPtr parentNode() const override;
    void setParentNode(NodeWeakPtr parentNode) override;

    ItemCreator *createCreator() const override;

private:
    NodeWeakPtr _parentNode;
};

} // namespace cute
} // namespace hierhin

#endif // HIERHIN_CUTE_ITEMIMPL_H
