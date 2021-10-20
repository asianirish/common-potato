#include "ChildGroup.h"
#

namespace hi {

ChildGroup::ChildGroup() : ChildGroup(nullptr)
{

}

ChildGroup::ChildGroup(const Node *owner) : _owner(owner)
{

}

const Node *ChildGroup::owner() const
{
    return _owner;
}

void ChildGroup::setOwner(const Node *owner)
{
    _owner = owner;
}

Item *ChildGroup::child(const QString &id) const
{
    //TODO: implement
    Q_UNUSED(id);
    return nullptr;
}

QMap<QString, Item *> ChildGroup::children() const
{
    //TODO: implement
    return {};
}

void ChildGroup::addChild(Item *child)
{
    //TODO: implement
    //TODO: check if the child is compatible
    Q_UNUSED(child);
}

QString ChildGroup::childItemClass() const
{
    return _childItemClass;
}

void ChildGroup::setChildItemClass(const QString &childItemClass)
{
    _childItemClass = childItemClass;
}

} // namespace hi
