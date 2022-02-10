#include "Neuron.h"

namespace nn {

Neuron::Neuron()
{

}

QMap<QString, PropertyDef> Neuron::propertyDefs() const
{
    auto defs = Essence::propertyDefs();

    {
        PropertyDef def;
        def.setName("value");
        def.setTypeId(QMetaType::Double);
        defs.insert("value", def);
    }

    return defs;
}

} // namespace nn
