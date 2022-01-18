#ifndef HIERHIN_DEF_NODEDEF_H
#define HIERHIN_DEF_NODEDEF_H

#include "ItemDef.h"
#include "ItemReq.h"

namespace hierhin {

namespace def {

class NodeDef : public ItemDef
{
public:
    NodeDef();

    QList<Role> roles() const;

    void validateChild(ItemPtr item, const Role &role) const;

    const QMap<Role, ItemReq> &childRequirements() const;
    void setChildRequirements(const QMap<Role, ItemReq> &newChildRequirements);
    void setChildRequirement(const ItemReq &req, const Role &role = Role());
    ItemReq childRequirement(const Role &role) const;

    ItemReq everyChildRequirement() const;
    void setEveryChildRequirement(const ItemReq &everyChildRequirement);

    BaseType requiredBaseType() const final;
    void setRequiredBaseType(const BaseType &requiredBaseType);

private:

    //maps roles onto item requirements
    QMap<Role, ItemReq> _childRequirements;

    ItemReq _everyChildRequirement;

    BaseType _requiredBaseType; //node or item
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_NODEDEF_H
