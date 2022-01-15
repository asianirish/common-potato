#include "LinkableEssence.h"

namespace hierhin {

LinkableEssence::LinkableEssence()
{

}

QStringList LinkableEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();
    //TODO: add a sys::Link action
    return lst;
}

ItemReq LinkableEssence::everyChildRequirement() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkOwnerEssence");
    req.setCanBeEssenceless(false);
    return req;
}


} // namespace hierhin
