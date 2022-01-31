#include "LinkOwnerEssence.h"
#include "LinkEssence.h"

namespace hierhin {

LinkOwnerEssence::LinkOwnerEssence()
{

}

ItemReq LinkOwnerEssence::everyChildRequirement() const
{
    ItemReq req;
    req.addClassName(ESSENCE_CLASS(hierhin::LinkEssence));
    req.setCanBeEssenceless(false);

    return req;
}

} // namespace hierhin
