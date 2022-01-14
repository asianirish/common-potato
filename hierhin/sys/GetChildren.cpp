#include "GetChildren.h"
#include "Node.h"

namespace hierhin {
namespace sys {

GetChildren::GetChildren()
{

}

QVariant GetChildren::actImpl(const QVariantList &args, Item *item)
{
    Q_UNUSED(args);

    Node *node = dynamic_cast<Node *>(item);

    if (!node) {
        return QVariant(); //TODO: or exception?
    }

    return QVariant::fromValue(node->childRefs());
}

} // namespace sys
} // namespace hierhin
