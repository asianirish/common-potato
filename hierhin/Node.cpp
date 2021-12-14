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

BaseType Node::baseType() const
{
    return BaseType::NODE;
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
