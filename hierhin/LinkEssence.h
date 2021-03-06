#ifndef HIERHIN_DEF_LINKESSENCE_H
#define HIERHIN_DEF_LINKESSENCE_H

#include "Essence.h"

namespace hierhin {

class LinkEssence : public Essence
{
    Q_OBJECT
public:
    LinkEssence();

//    void nodeDef(NodeDef &nd) const override;
//    QMap<Role, ItemReq> childRequirements() const override;
    QMap<QString, def::PropertyDef> propertyDefs() const override;
//    QStringList methodNames() const override;
};

} // namespace hierhin

#endif // HIERHIN_DEF_LINKESSENCE_H
