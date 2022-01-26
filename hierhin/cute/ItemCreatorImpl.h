#ifndef HIERHIN_CUTE_ITEMCREATORIMPL_H
#define HIERHIN_CUTE_ITEMCREATORIMPL_H

#include <ItemCreator.h>

namespace hierhin {
namespace cute {

class ItemCreatorImpl : public ItemCreator
{
public:
    ItemCreatorImpl();

private:
    ItemPtr createItem() const final;
    NodePtr createNode() const final;
};

} // namespace cute
} // namespace hierhin

#endif // HIERHIN_CUTE_ITEMCREATORIMPL_H
