#ifndef NN_NEURON_H
#define NN_NEURON_H

#include <hierhin/LinkableEssence.h>

using namespace hierhin;

namespace nn {

class Neuron : public hierhin::LinkableEssence
{
    Q_OBJECT
public:
    static const QString ASSOC_LINK_OWNER_ROLE;
    Neuron();

    QMap<QString, def::PropertyDef> propertyDefs() const override;

private:
    QList<std::pair<Role, QString> > linkRoles() const override;
};

} // namespace nn

#endif // NN_NEURON_H
