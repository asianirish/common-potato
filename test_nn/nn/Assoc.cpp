#include "Assoc.h"

namespace nn {

Assoc::Assoc()
{

}

QMap<QString, PropertyDef> Assoc::propertyDefs() const
{
    auto defs = hierhin::LinkEssence::propertyDefs();

    {
        PropertyDef def;
        def.setName("weight");
        def.setTypeId(QMetaType::Double);
        //TODO: set min & max
        defs.insert("weight", def);
    }

    return defs;
}

} // namespace nn
