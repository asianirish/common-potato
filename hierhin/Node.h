#ifndef HIERHIN_NODE_H
#define HIERHIN_NODE_H

#include "Item.h"
#include "nav/ItemRef.h"

#include "LinkEssence.h"

#include "Const.h"

namespace hierhin {

class Node : public virtual Item
{
public:
    Node();

    virtual bool containsId(const Id &id) = 0;

    ItemPtr child(const Id &id);
    virtual ConstItemPtr child(const Id &id) const = 0;

    ItemPtr childByRole(const Role &role);
    virtual ConstItemPtr childByRole(const Role &role) const = 0;

    virtual Role childRoleById(const Id &id) const = 0;

    void addChild(ItemPtr item, const Role &role = Role());

    virtual IdList idList() const = 0;

    QList<nav::ItemRef> childRefs() const;

    void setLink(nav::ItemRef &targetRef, bool isBidirectional = false, const Role &linkRole = Role(),
                 const QString &linkClass = ESSENCE_CLASS(hierhin::LinkEssence), const Role &ownerRole = Const::DEFAULT_LINK_OWNER_ROLE);

    QList<nav::ItemRef> targets(const Role &linkOwnerRole = Const::DEFAULT_LINK_OWNER_ROLE);

protected:
    virtual void nodeImplToMap(QVariantMap &mp) const = 0;
    virtual void nodeImplFromMap(const QVariantMap &mp) = 0;

    virtual void addChildImpl(ItemPtr item, const Role &role) = 0;
    virtual void assignRoleImpl(const Role &role, ItemPtr chld) = 0;

private:
    void nodeToMap(QVariantMap &mp) const final;
    void nodeFromMap(const QVariantMap &mp) final;

    //returns QString() if not mandatory
    QString childMandatoryClassName(const Role &role) const;

};

} // namespace hierhin

#endif // HIERHIN_NODE_H
