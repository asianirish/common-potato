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

    auto cg = _childGroups.value(childGroup);

    if (!cg->containsChild(id)) {
        //TODO: throw NoSuchAChild
        return nullptr;
    }

    return cg->child(id);
}

void Node::addChild(Item *item, const QString &childGroup)
{
    if (!_childGroups.contains(childGroup)) {
        //TODO: throw ChildGroupException
        return;
    }

    auto cg = _childGroups.value(childGroup);

    //TODO: check if child compatible

    cg->addChild(item);
/* TODO:
    addToRoot(item);
    */

}

QMap<QString, ChildGroupPtr> Node::childGroups() const
{
    if (_childGroups.isEmpty()) {
        _childGroups = createChildGroups();
    }

    return _childGroups;
}

ChildGroupPtr Node::defaultChildGroup() const
{
    auto cg = ChildGroupPtr::create(this);
    cg->setChildItemClass(Item::staticMetaObject.className()); //hi::Item
    return cg;
}

QMap<QString, ChildGroupPtr> Node::createChildGroups() const
{
    return QMap<QString, ChildGroupPtr>{{Node::DEFAULT_CHILD_GROUP_NAME, defaultChildGroup()}};
}

void Node::nodeToMap(QVariantMap &mp) const
{
    //TODO: implement (write children)
    Q_UNUSED(mp);
}

} // namespace hi
