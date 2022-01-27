#include "NodeImpl.h"

namespace hierhin {
namespace cute {

const QString NodeImpl::CHILDREN_KEY("children");
const QString NodeImpl::ROLES_KEY("roles");

NodeImpl::NodeImpl()
{

}

bool NodeImpl::containsId(const Id &id)
{
    return _children.contains(id);
}

ConstItemPtr NodeImpl::child(const Id &id) const
{
    return _children.value(id);
}

ConstItemPtr NodeImpl::childByRole(const Role &role) const
{
    return _children.valueByName(role);
}

IdList NodeImpl::idList() const
{
    return _children.keys();
}

void NodeImpl::nodeImplToMap(QVariantMap &mp) const
{
    QVariantMap childrenMap;
    QVariantMap rolesMap;

    for (const auto &child : _children) {
        childrenMap.insert(child->id(), child->toMap());
        rolesMap.insert(child->role(), child->id());
    }

    if (!childrenMap.isEmpty()) {
        mp.insert(CHILDREN_KEY, childrenMap);
    }

    if (!rolesMap.isEmpty()) {
        mp.insert(ROLES_KEY, rolesMap);
    }
}

void NodeImpl::nodeImplFromMap(const QVariantMap &mp)
{
    QScopedPointer<ItemCreator> cc(createCreator());

    auto childrenMap = mp.value(CHILDREN_KEY).toMap();

    for (auto &childVar : childrenMap) {
        auto child = cc->createItem(childVar.toMap());
        child->fromMap(childVar.toMap());
        addChild(child);
    }

    QVariantMap rolesMap = mp.value(ROLES_KEY).toMap();
    auto roleNames = rolesMap.keys();

    for (auto &roleName : roleNames) {
        auto id = rolesMap.value(roleName).toString();
        _children.rename(id, roleName);
    }
}

void NodeImpl::addChildImpl(ItemPtr item, const Role &role)
{
    _children.insert(item->id(), item, role);
}

void NodeImpl::assignRoleImpl(const Role &role, ItemPtr chld)
{
    _children.rename(chld->id(), role);
}


} // namespace cute
} // namespace hierhin
