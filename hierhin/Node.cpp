#include "Node.h"

namespace hierhin {

Node::Node()
{

}

void Node::addChild(ItemPtr item)
{
    //TODO: validate item

    addChildImpl(item);
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement
    //TODO: write links and named items
    nodeImplToMap(mp);
}

} // namespace hierhin
