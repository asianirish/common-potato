#include "LinkableEssence.h"
#include "Const.h"

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

    auto reqs = nonLinkChildRequirements();
    mp.insert(reqs);

    return mp;
}

QStringList LinkableEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();
    //TODO: add a sys::Link action
    return lst;
}

QList<std::pair<Role, QString> > LinkableEssence::linkRoles() const
{
    return {{Const::DEFAULT_LINK_OWNER_ROLE, QString("hierhin::LinkOwnerEssence")}}; //TODO: const
}

QMap<Role, ItemReq> LinkableEssence::nonLinkChildRequirements() const
{
    return {};
}


} // namespace hierhin
