#include "LinkOwnerEssence.h"

namespace hierhin {

LinkOwnerEssence::LinkOwnerEssence()
{

}

ItemReq LinkOwnerEssence::everyChildRequirement() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkEssence");
    req.setCanBeEssenceless(false);

    return req;
}

} // namespace hierhin
