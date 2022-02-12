#include "LinkEssence.h"
#include <nav/ItemRef.h>

#include "Const.h"

namespace hierhin {

LinkEssence::LinkEssence()
{

}

QMap<QString, PropertyDef> LinkEssence::propertyDefs() const
{
    int typeId = nav::ItemRef::typeId();

    PropertyDef targetDef;
    targetDef.setName(Const::TARGET_PROP);
    targetDef.setTypeId(typeId);

    PropertyDef sourceDef;
    sourceDef.setName(Const::SOURCE_PROP);
    sourceDef.setTypeId(typeId);

    PropertyDef bidirDef;
    bidirDef.setName(Const::BIDIR_PROP);
    bidirDef.setTypeId(QMetaType::Bool);

    return {
        {targetDef.name(), targetDef},
        {sourceDef.name(), sourceDef},
        {bidirDef.name(), bidirDef}
    };
}

} // namespace hierhin
