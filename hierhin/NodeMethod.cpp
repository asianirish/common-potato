#include "NodeMethod.h"
#include "Node.h"

namespace hierhin {

NodeMethod::NodeMethod()
{

}

QVariant NodeMethod::actImpl(const QVariantList &args, Item *item)
{
    Node *node = dynamic_cast<Node *>(item);

    if (!node) {
//TODO:        throw ItemIsNotANode();
        return QVariant();
    }

    return actNodeImpl(args, node);
}

} // namespace hierhin
