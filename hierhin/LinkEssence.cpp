#include "LinkEssence.h"
#include <nav/ItemRef.h>

namespace hierhin {
namespace def {

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
    targetDef.setName("source"); //TODO: const
    targetDef.setTypeId(typeId);

    return {
        {targetDef.name(), targetDef},
        {sourceDef.name(), sourceDef}
    };
}

} // namespace def
} // namespace hierhin
