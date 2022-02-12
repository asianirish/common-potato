#include "Assoc.h"

#include <val/Range.h>

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

        auto range = val::ValidatorPtr(new val::Range<double>(-1., 1.));
        def.addValidator(range);

        defs.insert("weight", def);
    }

    return defs;
}

} // namespace nn
