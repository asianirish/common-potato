#ifndef HIERHIN_DEF_LINKEDESSENCE_H
#define HIERHIN_DEF_LINKEDESSENCE_H

#include "Essence.h"
#include "nav/ItemRef.h"

#include <QObject>

namespace hierhin {

class LinkableEssence : public Essence
{
    Q_OBJECT
public:
    LinkableEssence();

//    void nodeDef(NodeDef &nd) const override;
//    QMap<Role, ItemReq> childRequirements() const override;
//    QMap<QString, def::PropertyDef> propertyDefs() const override;
    QStringList methodNames() const override;
    ItemReq everyChildRequirement() const override;

};

} // namespace hierhin

#endif // HIERHIN_DEF_LINKEDESSENCE_H
