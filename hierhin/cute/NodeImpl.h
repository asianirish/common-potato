#ifndef HIERHIN_CUTE_NODEIMPL_H
#define HIERHIN_CUTE_NODEIMPL_H

#include "ItemImpl.h"

#include "../ItemContainer.h"

#include "../Node.h"

namespace hierhin {
namespace cute {

class NodeImpl : public virtual hierhin::Node, public hierhin::cute::ItemImpl
{
public:
    static const QString CHILDREN_KEY;
    static const QString ROLES_KEY;
    NodeImpl();

    // Node interface
public:
    bool containsId(const Id &id) override;
    ConstItemPtr child(const Id &id) const override;
    ConstItemPtr childByRole(const Role &role) const override;
    Role childRoleById(const Id &id) const override;
    IdList idList() const override;

protected:
    void nodeImplToMap(QVariantMap &mp) const override;
    void nodeImplFromMap(const QVariantMap &mp) override;
    void addChildImpl(ItemPtr item, const Role &role) override;
    void assignRoleImpl(const Role &role, ItemPtr chld) override;

private:
    ItemContainer _children;
};

typedef NodeImpl NodeHashImpl;

} // namespace cute
} // namespace hierhin

#endif // HIERHIN_CUTE_NODEIMPL_H
