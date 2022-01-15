#include "LinkedEssence.h"

namespace hierhin {

LinkedEssence::LinkedEssence()
{

}

QStringList LinkedEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();
    //TODO: add a sys::Link action
    return lst;
}

ItemReq LinkedEssence::everyChildRequirement() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkOwnerEssence");
    req.setCanBeEssenceless(false);
    return req;
}


} // namespace hierhin
