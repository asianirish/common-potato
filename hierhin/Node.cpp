#include "Node.h"

namespace hierhin {

Node::Node()
{

}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement
    //TODO: write links and named items
    toMapNodeImplSpecific(mp);
}

} // namespace hierhin
