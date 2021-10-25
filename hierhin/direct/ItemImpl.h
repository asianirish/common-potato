#ifndef DIRECT_ITEMIMPL_H
#define DIRECT_ITEMIMPL_H

#include "Item.h"

#include <QHash>

namespace hierhin {
namespace direct {

class ItemImpl : public virtual Item
{
public:
    NodePtr parentNode() const override;
    void setParentNode(NodePtr parentNode) override;

private:
    NodePtr _parentNode;
};

} // namespace direct
} // namespace hierhin

#endif // DIRECT_ITEMIMPL_H
