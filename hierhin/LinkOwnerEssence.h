#ifndef HIERHIN_LINKOWNERESSENCE_H
#define HIERHIN_LINKOWNERESSENCE_H

#include "Essence.h"

namespace hierhin {

class LinkOwnerEssence : public Essence
{
    Q_OBJECT
public:
    LinkOwnerEssence();

//    void nodeDef(NodeDef &nd) const override;
//    QMap<Role, ItemReq> childRequirements() const override;
//    QMap<QString, def::PropertyDef> propertyDefs() const override;
//    QStringList methodNames() const override;
    ItemReq everyChildRequirement() const override;
};

} // namespace hierhin

#endif // HIERHIN_LINKOWNERESSENCE_H
