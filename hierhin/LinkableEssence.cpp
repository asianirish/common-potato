#include "LinkableEssence.h"

namespace hierhin {

LinkableEssence::LinkableEssence()
{

}

QMap<Role, ItemReq> LinkableEssence::childRequirements() const
{
    QMap<Role, ItemReq> mp;
    auto lnkRls = linkRoles();

    for (auto &pr : lnkRls) {
        ItemReq req;
        req.setClassNames({pr.second});
        req.setIsMandatory(true);
        req.setCanBeEssenceless(false);

        mp.insert(pr.first, req);
    }

    return mp;
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

QList<std::pair<Role, QString> > LinkableEssence::linkRoles() const
{
    return {{QString("links"), QString("hierhin::LinkOwnerEssence")}}; //TODO: const
}


} // namespace hierhin
