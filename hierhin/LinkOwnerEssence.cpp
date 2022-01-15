#include "LinkOwnerEssence.h"

namespace hierhin {

LinkOwnerEssence::LinkOwnerEssence()
{

}

QMap<Role, ItemReq> LinkOwnerEssence::childRequirements() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkEssence");
    req.setCanBeEssenceless(false);

    return {{QString(), req}}; //without a role
}

ItemReq LinkOwnerEssence::everyChildRequirement() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkEssence");
    req.setCanBeEssenceless(false);

    return req;
}

} // namespace hierhin
