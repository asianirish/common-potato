#include "Neuron.h"
#include <val/Range.h>
#include <hierhin/Node.h>

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

        auto range = val::ValidatorPtr(new val::Range<double>(-1., 1.));
        def.addValidator(range);

        defs.insert("value", def);
    }

    {
        PropertyDef def;
        def.setName(Node::LINK_BACK_REF_SIGN + "links"); //TODO: use accocs and as Const
        def.setTypeId(QMetaType::QVariantList);

        defs.insert(Node::LINK_BACK_REF_SIGN + "links", def); //TODO: use accocs and as Const
    }

    return defs;
}

} // namespace nn
