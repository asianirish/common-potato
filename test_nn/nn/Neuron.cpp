#include "Neuron.h"
#include <val/Range.h>
#include <hierhin/Node.h>

namespace nn {

const QString Neuron::ASSOC_LINK_OWNER_ROLE(LinkableEssence::DEFAULT_LINK_OWNER_ROLE);

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
        def.setName(Node::backRef(Neuron::ASSOC_LINK_OWNER_ROLE));
        def.setTypeId(QMetaType::QVariantList);

        defs.insert(Node::backRef(Neuron::ASSOC_LINK_OWNER_ROLE), def);
    }

    return defs;
}

} // namespace nn
