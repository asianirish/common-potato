#include "Node.h"

namespace hierhin {

Node::Node()
{

}

void Node::addChild(ItemPtr item, const Role &role)
{
    definition().validateChild(item, role);

    addChildImpl(item, role);
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement
    //TODO: write links and named items
    nodeImplToMap(mp);
}

} // namespace hierhin
