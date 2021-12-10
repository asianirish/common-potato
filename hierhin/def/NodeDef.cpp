#include "NodeDef.h"
#include "ex/NoSuchRoleExceptin.h"
#include "ex/IncompatibleEssenceClass.h"
#include "../Item.h"

namespace hierhin {
namespace def {

NodeDef::NodeDef()
{
    setChildRequirement(ItemReq("hierhin::Essence"), Role());
}

QList<Role> NodeDef::roles() const
{
    return _childRequirements.keys();
}

void NodeDef::validateChild(ItemPtr item, const Role &role) const
{
    if (!role.isEmpty() && !roles().contains(role)) {
        ex::NoSuchRoleExceptin ex;
        ex.setRole(role);
        throw ex;
    }

    auto req = _childRequirements.value(role);
    req.validate(item); //TODO: display role on exception

}

const QMap<Role, ItemReq> &NodeDef::childRequirements() const
{
    return _childRequirements;
}

void NodeDef::setChildRequirements(const QMap<Role, ItemReq> &newChildRequirements)
{
    _childRequirements = newChildRequirements;
}

void NodeDef::setChildRequirement(const ItemReq &req, const Role &role)
{
    _childRequirements.insert(role, req);
}

} // namespace def
} // namespace hierhin
