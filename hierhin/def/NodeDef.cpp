#include "NodeDef.h"
#include "ex/NoSuchRole.h"
#include "ex/IncompatibleEssenceClass.h"
#include "../Item.h"

namespace hierhin {
namespace def {

NodeDef::NodeDef()
{
    setChildRequirement(ItemReq("hierhin::Essence"), Role());
    _everyChildRequirement.setAlwaysValid(true);
}

QList<Role> NodeDef::roles() const
{
    return _childRequirements.keys();
}

void NodeDef::validateChild(ItemPtr item, const Role &role) const
{
    if (!role.isEmpty() && !roles().contains(role)) {
        ex::NoSuchRole ex(role);
        throw ex;
    }

    _everyChildRequirement.validate(item, role);

    auto req = _childRequirements.value(role);
    req.validate(item, role);

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

ItemReq NodeDef::everyChildRequirement() const
{
    return _everyChildRequirement;
}

void NodeDef::setEveryChildRequirement(const ItemReq &everyChildRequirement)
{
    _everyChildRequirement = everyChildRequirement;
}

} // namespace def
} // namespace hierhin
