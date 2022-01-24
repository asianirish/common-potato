#ifndef DIRECT_NODEIMPL_H
#define DIRECT_NODEIMPL_H

#include "Node.h"
#include "ItemImpl.h"

#include <QMap>
#include <QHash>

namespace hierhin {
namespace direct {

template <typename C>
class NodeImpl : public virtual Node, public ItemImpl<C>
{
public:
    static const QString CHILDREN_KEY;
    static const QString ROLES_KEY;

    bool containsId(const Id &id) final;

    ConstItemPtr child(const Id &id) const final;

    ConstItemPtr childByRole(const Role &role) const final;

    ConstItemPtr childByName(const QString &name) const final;

    IdList idList() const final;

protected:
    void nodeImplToMap(QVariantMap &mp) const final;
    void addChildImpl(ItemPtr item, const Role &role) final;
    void nodeImplFromMap(const QVariantMap &mp) final;
    void assignRoleImpl(const Role &role, ItemPtr chld) final;
private:
    C _children;
    QMap<Role, ItemWeakPtr> _roles;
};

typedef NodeImpl<QMap<Id, ItemPtr> > NodeMapImpl;
typedef NodeImpl<QHash<Id, ItemPtr> > NodeHashImpl;

template<typename C>
const QString NodeImpl<C>::CHILDREN_KEY("children");

template<typename C>
const QString NodeImpl<C>::ROLES_KEY("roles");

template<typename C>
bool NodeImpl<C>::containsId(const Id &id)
{
    return _children.contains(id);
}

template<typename C>
ConstItemPtr NodeImpl<C>::child(const Id &id) const
{
    return _children.value(id);
}

template<typename C>
ConstItemPtr NodeImpl<C>::childByRole(const Role &role) const
{
    return _roles.value(role).lock();
}

template<typename C>
ConstItemPtr NodeImpl<C>::childByName(const QString &name) const
{
    Q_UNUSED(name)
    throw "NOT SUPPORTED (YET?)"; //TODO:
}

template<typename C>
void NodeImpl<C>::addChildImpl(ItemPtr item, const Role &role)
{
    if (!role.isEmpty()) {
        _roles.insert(role, item.toWeakRef());
    }

    _children.insert(item->id(), item);

    item->setParentNode(sharedFromThis().template dynamicCast<Node>().toWeakRef());
}

template<typename C>
IdList NodeImpl<C>::idList() const
{
    return _children.keys();
}

template<typename C>
void NodeImpl<C>::nodeImplToMap(QVariantMap &mp) const
{
    if (!_children.isEmpty()) {
        QVariantMap childrenMap;
        for (auto child : _children) {
            childrenMap.insert(child->id(), child->toMap());
        }
        mp.insert(CHILDREN_KEY, childrenMap);
    }

    if (!_roles.isEmpty()) {
        QVariantMap rolesMap;
        auto keys = _roles.keys();
        for (auto &key : keys) {
            auto role = _roles.value(key).lock();
            rolesMap.insert(key, role->id());
        }
        mp.insert(ROLES_KEY, rolesMap);
    }
}

template<typename C>
void NodeImpl<C>::nodeImplFromMap(const QVariantMap &mp)
{
    QScopedPointer<ItemCreator> cc(createCreator());

    auto childrenMap = mp.value(CHILDREN_KEY).toMap();
    for (auto &childVar : childrenMap) {
        auto child = cc->createItem(childVar.toMap());
        child->fromMap(childVar.toMap());
        _children.insert(child->id(), child);
        child->setParentNode(sharedFromThis().template dynamicCast<Node>().toWeakRef());
//TODO:        addChild(child); //TODO: role
    }

    QVariantMap rolesMap = mp.value(ROLES_KEY).toMap();
    auto roleNames = rolesMap.keys();

    for (auto &roleName : roleNames) {
        auto id = rolesMap.value(roleName);
        ItemPtr child = _children.value(id.toString());
        auto weakChild = child.toWeakRef();
        _roles.insert(roleName, weakChild);
    }
}

template<typename C>
void NodeImpl<C>::assignRoleImpl(const Role &role, ItemPtr chld)
{
    auto weakChld = chld.toWeakRef();
    _roles.insert(role, weakChld);
}

} // namespace direct
} // namespace hierhin

#endif // DIRECT_NODEIMPL_H
