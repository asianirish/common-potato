#include "LinkedEssence.h"

namespace hierhin {

LinkedEssence::LinkedEssence()
{

}

QMap<Role, ItemReq> LinkedEssence::childRequirements() const
{
    ItemReq req;
    req.addClassName("hierhin::LinkOwnerEssence");
    req.setCanBeEssenceless(false);

    return {{"links", req}}; //without a role
}

QStringList LinkedEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();
    //TODO: add a sys::Link action
    return lst;
}


} // namespace hierhin
