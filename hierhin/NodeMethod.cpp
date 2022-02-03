#include "NodeMethod.h"
#include "Node.h"
#include "ex/NotANode.h"

namespace hierhin {

NodeMethod::NodeMethod()
{

}

QVariant NodeMethod::actImpl(const QVariantList &args, Item *item)
{
    Node *node = dynamic_cast<Node *>(item);

    if (!node) {
        if (item) {
            throw ex::NotANode(item->id());
        } else {
            throw ex::NotANode(); //TODO: in Method::simplyAct
        }
    }

    return actNodeImpl(args, node);
}

} // namespace hierhin
