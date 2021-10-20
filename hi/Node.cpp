#include "Node.h"

namespace hi {

const QString Node::DEFAULT_CHILD_GROUP_NAME("children");

Node::Node(QObject *parent) : Item(parent)
{

}

Item *Node::child(const QString &id, const QString &childGroup) const
{
    if (!_childGroups.contains(childGroup)) {
        //TODO: throw ChildGroupException
        return nullptr;
    }

    ChildGroup cg = _childGroups.value(childGroup);
    auto children = cg.children();

    if (!children.contains(id)) {
        //TODO: throw NoSuchAChild
        return nullptr;
    }


    //TODO: implement
    return nullptr;
}

void Node::addChild(Item *item, const QString &childGroup)
{
    if (!_childGroups.contains(childGroup)) {
        //TODO: throw ChildGroupException
        return;
    }

    ChildGroup cg = _childGroups.value(childGroup);

    //TODO: check if child compatible

    auto itemId = item->id();
    _children.insert(itemId, {itemId, item});
/* TODO:
    addToRoot(item);
    */

}

QMap<QString, ChildGroup> Node::childGroups() const
{
    if (_childGroups.isEmpty()) {
        _childGroups = createChildGroups();
    }

    return _childGroups;
}

ChildGroup Node::defaultChildGroup() const
{
    ChildGroup cg(this);
    cg.setChildItemClass(Item::staticMetaObject.className()); //hi::Item
    return cg;
}

QMap<QString, ChildGroup> Node::createChildGroups() const
{
    return QMap<QString, ChildGroup>{{Node::DEFAULT_CHILD_GROUP_NAME, defaultChildGroup()}};
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement (write children)
    Q_UNUSED(mp);
}

} // namespace hi
