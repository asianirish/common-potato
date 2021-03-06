#ifndef HIERHIN_DEF_LINKABLEESSENCE_H
#define HIERHIN_DEF_LINKABLEESSENCE_H

#include "Essence.h"
#include "nav/ItemRef.h"

#include <QObject>

namespace hierhin {

class LinkableEssence : public Essence
{
    Q_OBJECT
public:
    static const Role DEFAULT_LINK_OWNER_ROLE;

    LinkableEssence();

//    void nodeDef(NodeDef &nd) const override;
    QMap<Role, ItemReq> childRequirements() const final;
//    QMap<QString, def::PropertyDef> propertyDefs() const override;
    QStringList methodNames() const override;
//    ItemReq everyChildRequirement() const override;

private:

    virtual QList<std::pair<Role, QString> > linkRoles() const;
    virtual QMap<Role, ItemReq> nonLinkChildRequirements() const;
};

} // namespace hierhin

#endif // HIERHIN_DEF_LINKABLEESSENCE_H
