#include "Node.h"

namespace hierhin {

Node::Node()
{

}

ItemPtr Node::child(const Id &id)
{
    const Node *cnode = dynamic_cast<const Node*>(this);
    return cnode->child(id).constCast<Item>();
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

void Node::nodeFromMap(const QVariantMap &mp)
{
    //TODO: read links
    nodeImplFromMap(mp);
}

} // namespace hierhin
