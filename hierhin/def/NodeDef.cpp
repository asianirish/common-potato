#include "NodeDef.h"
#include "ex/NoSuchRole.h"
#include "ex/IncompatibleEssenceClass.h"
#include "../Item.h"

namespace hierhin {
namespace def {

NodeDef::NodeDef() : _requiredBaseType(BaseType::NODE)
{
    setChildRequirement(ItemReq("hierhin::Essence"), Role());
    _everyChildRequirement.setAlwaysValid(true);
}

QList<Role> NodeDef::roles() const
{
    //TODO: if (_requiredBaseType == BaseType::ITEM)
    return _childRequirements.keys();
}

void NodeDef::validateChild(ItemPtr item, const Role &role) const
{
    //TODO: if (_requiredBaseType == BaseType::ITEM)

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
    //TODO: if (_requiredBaseType == BaseType::ITEM)
    return _childRequirements;
}

void NodeDef::setChildRequirements(const QMap<Role, ItemReq> &newChildRequirements)
{
    _childRequirements = newChildRequirements;
}

void NodeDef::setChildRequirement(const ItemReq &req, const Role &role)
{
    //TODO: if (_requiredBaseType == BaseType::ITEM)
    _childRequirements.insert(role, req);
}

ItemReq NodeDef::everyChildRequirement() const
{
    //TODO: if (_requiredBaseType == BaseType::ITEM)
    return _everyChildRequirement;
}

void NodeDef::setEveryChildRequirement(const ItemReq &everyChildRequirement)
{
    //TODO: if (_requiredBaseType == BaseType::ITEM)
    _everyChildRequirement = everyChildRequirement;
}

BaseType NodeDef::requiredBaseType() const
{
    return _requiredBaseType;
}

void NodeDef::setRequiredBaseType(const BaseType &requiredBaseType)
{
    _requiredBaseType = requiredBaseType;
}

} // namespace def
} // namespace hierhin
