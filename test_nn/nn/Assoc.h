#ifndef NN_ASSOC_H
#define NN_ASSOC_H

#include <hierhin/LinkEssence.h>

using namespace hierhin;

namespace nn {

class Assoc : public hierhin::LinkEssence
{
    Q_OBJECT
public:
    Assoc();

    QMap<QString, def::PropertyDef> propertyDefs() const override;
};

} // namespace nn

#endif // NN_ASSOC_H
