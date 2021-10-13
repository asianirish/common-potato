#include "Node.h"

namespace hi {

Node::Node(QObject *parent) : Item(parent)
{

}

Item *Node::child(const QString &id) const
{
    ItemRef itemRef = _children.value(id, ItemRef(id));

    if (itemRef.item()) {
        return itemRef.item();
    }

    return nullptr; //TODO: else return fromRoot(id);
}

void Node::addChild(Item *item)
{
    //TODO: check if child compatible

    auto itemId = item->id();
    _children.insert(itemId, {itemId, item});
/* TODO:
    addToRoot(item);
    */

}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement (write children)
    Q_UNUSED(mp);
}

} // namespace hi
