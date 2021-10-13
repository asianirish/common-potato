#include "Node.h"

namespace hi {

Node::Node(QObject *parent) : Item(parent)
{

}

Item *Node::child(const QString &id) const
{
    return _children.value(id, nullptr);
}

void Node::addChild(Item *item)
{
    auto itemId = item->id();
    _children.insert(itemId, item);
/* TODO:
    if (!isInHierarchy(itemId)) {
        item->setParent(this);
    }
    */
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement (write children)
    Q_UNUSED(mp);
}

} // namespace hi
