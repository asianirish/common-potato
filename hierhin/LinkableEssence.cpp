#include "LinkableEssence.h"
#include "LinkOwnerEssence.h"

#include "Const.h"

#include "sys/SetLink.h"

namespace hierhin {

const Role LinkableEssence::DEFAULT_LINK_OWNER_ROLE("links");

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
#if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
    auto keys = reqs.keys();
    for (auto &role : keys) {
        auto req = reqs.value(role);
        mp.insert(role, req);
    }
#else
    mp.insert(reqs);
#endif

    return mp;
}

QStringList LinkableEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();

    lst.append(METHOD_CLASS(sys::SetLink));
    //TODO: add linkable specific Methods here

    return lst;
}

QList<std::pair<Role, QString> > LinkableEssence::linkRoles() const
{
    return {{DEFAULT_LINK_OWNER_ROLE, QString(ESSENCE_CLASS(hierhin::LinkOwnerEssence))}};
}

QMap<Role, ItemReq> LinkableEssence::nonLinkChildRequirements() const
{
    return {};
}


} // namespace hierhin
