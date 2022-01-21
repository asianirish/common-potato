#include "LinkEssence.h"
#include <nav/ItemRef.h>

namespace hierhin {

LinkEssence::LinkEssence()
{

}

QMap<QString, PropertyDef> LinkEssence::propertyDefs() const
{
    int typeId = nav::ItemRef::typeId();

    PropertyDef targetDef;
    targetDef.setName("target"); //TODO: const
    targetDef.setTypeId(typeId);

    PropertyDef sourceDef;
    sourceDef.setName("source"); //TODO: const
    sourceDef.setTypeId(typeId);

    return {
        {targetDef.name(), targetDef},
        {sourceDef.name(), sourceDef}
    };
}

} // namespace hierhin
